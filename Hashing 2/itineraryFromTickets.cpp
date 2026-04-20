#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

void printItinerary(unordered_map<string, string> &tickets){
    //to store the "to" info

    unordered_set<string> to;

    for(pair<string, string> ticket : tickets){
        to.insert(ticket.second); // inserting all the destinations in the "to" set;
    }

    string start = "";

    for(pair<string, string> ticket : tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }
    }
// printing itinerary 
    cout << start << " => ";
    while(tickets.count(start)){
        cout << tickets[start] << " => "; // 
        start = tickets[start]; // destination ko start bana diya
    }
    cout << "destination reached " << endl;

}

int main(){
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);

    return 0;
}