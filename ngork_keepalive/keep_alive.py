import json
import subprocess
import time
from pathlib import Path
import atexit
import boto3
import requests
import datetime

import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText


ngrokDir="/home/pi/"
port="22"



localhost_url = "http://localhost:4040/api/tunnels"

def send_email(tunnel_address):
    # mail settings:
    print("Mail sending in progress ")
    sender_address = 'sender@gmail.com'
    sender_pass = 'app passcode' 
    receiver_address = 'receiver@gmail.com'

    #Setup the MIME
    message = MIMEMultipart()
    message['From'] = sender_address
    message['To'] = receiver_address

    message['Subject'] = "The ssh address for pi2 changed "
    mail_content = "Hello Here is the updated tunnel address :"+str(tunnel_address)+" at "+time.ctime() 
    #The body and the attachments for the mail
    message.attach(MIMEText(mail_content, 'plain'))

    #Create SMTP session for sending the mail
    session = smtplib.SMTP('smtp.gmail.com', 587) #use gmail with port
    session.starttls() #enable security
    session.login(sender_address, sender_pass) #login with mail_id and password
    text = message.as_string()
    session.sendmail(sender_address, receiver_address, text)
    session.quit()
    print("Mail Sent")

def get_ngrok_url(ngrok_req):
    j = json.loads(ngrok_req)
    tunnel_url = j['tunnels'][len(j['tunnels'])-1]['public_url']
    #print(tunnel_url)
    return tunnel_url

def start_ngrok():
    global ngrokDir
    command = "ngrok"
    executable = str(Path(ngrokDir, command))
    ngrok = subprocess.Popen([executable, 'tcp',  port])
    atexit.register(ngrok.terminate)
    time.sleep(3)
    tunnel_url = requests.get(localhost_url).text
    tunnel_address = get_ngrok_url(tunnel_url)
    print("ngrok created {tunnel_address}".format(tunnel_address=tunnel_address))
    send_email(tunnel_address)
    time.sleep(21600)
    return tunnel_address


# Check if ngrok is running
def is_ngrok_running():
    try:
        ngrok_req = requests.get(localhost_url).text
        tunnel_address = get_ngrok_url(ngrok_req)
        print(tunnel_address) 
        #r = requests.get(tunnel_address)
        #print(r)
    except Exception as e:
        print("exception", e)
        #time.sleep(300)
        return start_ngrok()



is_ngrok_running()
# time.sleep(300)
