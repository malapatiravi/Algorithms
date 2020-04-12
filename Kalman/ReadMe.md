# Kalman Filter
## Lesson 1:Intro to Kalman Filter
1. https://www.youtube.com/watch?v=BkjQzEyJWrE -- Introduction of Gaussian
2. Monte Carlo Localization also known as particle filter localization. Multi model and discrete
3. Kalman Filter is Unimodel, continuous and symmetrical
4. Gaussian is continuous function and is characterized by two parameters that is width of the gaussian and height of the gaussian
   Width of the gaussian is variance and height of the gaussian is mean.
   
5. Gaussian function F(x) = exp(-1/2((x-Mu)^2/sig^2))/(sqrt(2*pi*sig^2))
6. Variance Comparision: https://www.youtube.com/watch?v=TGdMG81hXc8&feature=emb_logo
7. Preffered Gaussian: https://www.youtube.com/watch?time_continue=2&v=sBsju-6nQWI&feature=emb_logo
8. Evaluate Gaussian: https://www.youtube.com/watch?time_continue=1&v=4-0nBfsD4jo&feature=emb_logo
9. Maximize Gaussian: https://www.youtube.com/watch?v=fRYtUP0P4Lg&feature=emb_logo
```from math import *

def f(mu, sigma2, x):
    return 1/sqrt(2.*pi*sigma2) * exp(-.5*(x-mu)**2/sigma2)
print f(10., 4., 8.)
```

## Lesson 2: Measurment and Motion
1. The Kalman Filter represents our distributions by Gaussians and iterates on two main cycles.
a. 
