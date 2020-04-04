/*
* 100 floors building
* 26 eggs
* Find the floor where it starts breaking for the first time. 
* log(n)
* log(100) < 26
* 1,2,3
* first ind = 0 last Ind = 9
* mid = (9+0)/2 = 4 , floor is 6
first ind = 4 last ind = 9
1,2,3,4,5,6,7,8,9, 10
5
1, 5
1,2
*/

#include <iostream>
#include <vector>

int getFloorEggBreaks(int first_ind, int last_ind, std::vector<bool> &floor_map)
{
    if (last_ind - first_ind <= 1)
    {
        
        if (floor_map[first_ind] == true)
        {
            return first_ind;
        }
        else if (floor_map[last_ind] == true)
        {
            return last_ind;
        }
        else
        {
            //Throw error never should come here
        }
    }


    int mid = first_ind + (last_ind - first_ind) / 2;
    // if(floor_map[mid]==true)
    // {
    //     return mid;
    // }
    if (floor_map[mid] == true)
    {
        //go tot he lower side
        return getFloorEggBreaks(first_ind, mid, floor_map);
    }
    else
    {
        //go to the upper side
        return getFloorEggBreaks(mid + 1, last_ind, floor_map);
    }
}

/*1-100
1-50 or 50 -100 -- 1 leg
52 54 55 56*/
/*1-100
1-49*/
int getFirstFloorEggBreaks(int numOfEggs, std::vector<bool> &floor_map)
{
    int first_ind = 0;
    int last_ind = floor_map.size() - 1;
 
    if (floor_map[first_ind] == true)
    {
        return first_ind;
    }
    return getFloorEggBreaks(first_ind, last_ind, floor_map);
}

void getUnitTestcase(int start_break, int total_floors, std::vector<bool> &floors)
{
    start_break = start_break + 1;
    for (int i = 0; i < total_floors; i++)
    {
        if (i >= start_break-1)
        {
            floors.push_back(true);
        }
        else
        {
            floors.push_back(false);
        }
    }
}
int main()
{
    int start_break = 11;
    int total_floors = 100;
    std::vector<bool> floors;
    getUnitTestcase(start_break, total_floors, floors);
    std::cout << getFirstFloorEggBreaks(26, floors) << std::endl;

    start_break = 13;
    total_floors = 100;
    floors.clear();
    getUnitTestcase(start_break, total_floors, floors);
    std::cout << getFirstFloorEggBreaks(26, floors) << std::endl;

    start_break = 15;
    total_floors = 100;
    floors.clear();
    getUnitTestcase(start_break, total_floors, floors);
    std::cout << getFirstFloorEggBreaks(26, floors) << std::endl;

    start_break = 1;
    total_floors = 100;
    floors.clear();
    getUnitTestcase(start_break, total_floors, floors);
    std::cout << getFirstFloorEggBreaks(26, floors) << std::endl;

    start_break = 99;
    total_floors = 100;
    floors.clear();
    getUnitTestcase(start_break, total_floors, floors);
    std::cout << getFirstFloorEggBreaks(26, floors) << std::endl;

    start_break = 15;
    total_floors = 1000;
    floors.clear();
    getUnitTestcase(start_break, total_floors, floors);
    std::cout << getFirstFloorEggBreaks(26, floors) << std::endl;
}