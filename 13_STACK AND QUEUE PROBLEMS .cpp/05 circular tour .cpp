/*You are required to complete this method*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int start;
        int balance;
        int defecient = 0;

        for (int i = 0; i < n; i++)
        {

            // balance petrol to reach next petrol pump
            balance += p[i].petrol - p[i].distance;

            // truck can't get through start
            if (balance < 0)
            {

                // how much petrol truck need
                defecient += balance;

                // new start
                start = i + 1;

                // assigning balance to 0
                balance = 0;
            }
        }

        // if truck can reach all petorl pump from that start than return start
        if (balance + defecient >= 0)
            return start;

        else
            return -1;
    }
};

// Link of the Problem -> https://practice.geeksforgeeks.org/problems/circular-tour/1

/**********************************************************/

// Author's solution

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // considering first petrol pump as a starting point.
        int start = 0;
        int end = 1;
        int cur_pet = p[start].petrol - p[start].distance;

        // we run a loop while all petrol pumps are not visited and we have
        // reached first petrol pump again with 0 or more petrol.
        while (end != start or cur_pet < 0)
        {
            // if current amount of petrol in truck becomes less than 0,
            // then remove the starting petrol pump from tour.
            while (cur_pet < 0 and start != end)
            {
                // removing starting petrol pump and changing starting point.
                cur_pet -= p[start].petrol - p[start].distance;
                start = (start + 1) % n;

                // if 0 is being considered as start again, then there
                // is no possible solution.
                if (start == 0)
                    return -1;
            }
            // adding a petrol pump to current tour.
            cur_pet += p[end].petrol - p[end].distance;
            end = (end + 1) % n;
        }
        // returning starting point.
        return start;
    }
};