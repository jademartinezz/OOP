/* This program is a Weather Forecast database that gives relays to the user the forecast for that day as live data.
This program will also give the user information and suggestions about appropriate apparel based on the weather for that day.
The program retrieves real time data from weather.com*/
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <typeinfo>
using namespace std;
//Use of namespace (not std)
namespace Time_Time_of_day{
    template <typename T>
    T Time_combo(T Time_of_day,T Time) {
        return (Time_of_day,Time);
    };
}

//Weather data class and objects
class weatherData {
    public: 
    string day;         //day of the week
    string time;        //in standard time (not military)
    string current_weather;
    string time_of_day;
    int temp;           // in farenheit

    //Constructor
    weatherData(string day, string time, string current_weather, int temp) { 
        this->day = day;
        this->time = time;
        this->current_weather = current_weather;
        this->temp = temp;
    }

    //Exception handling
    weatherData(string day, string time, string current_weather, string time_of_day, int temp) {
        if (typeid(day) != typeid(string)){
            throw 100;
        }
        else if (typeid(temp) != typeid(int)){
            throw 99;
        }
        else {
            this->day = day;
            this->time = time;
            this->current_weather = current_weather;
            this->time_of_day = time_of_day;
            this->temp = temp;
        }
    };

    //Access weather data file to read
    void print_vector_to_file (vector<weatherData> &weatherInfo) {
        ifstream infile("Weather.txt");
        string line;

        int d = 1;
        while(getline(infile, line)) {
            ++d;        
        };
    
        infile.close();
        ofstream outfile;
        outfile.open ("Weather.txt", ios::app);
        if (!outfile.is_open()) {
            cout << "The weather forecast could not be accessed at this time. Please try again later." << endl;
        }  

        for (int i = 0; i < weatherInfo.size(); i ++ ) {
            outfile << weatherInfo[i].day << "," << weatherInfo[i].time << "," << weatherInfo[i].current_weather << ","
            << weatherInfo[i].temp << "," << weatherInfo[i].time_of_day << endl;
        }

        outfile.close();
    }
};

int main() {
    //Implementing system date 
    auto now = time(0);
    char* dt = ctime(&now);

    cout << "Today is " << dt << endl;
    vector <weatherData> weatherInfo;
    weatherData info;
    string day, time, current_weather, time_of_day;
    int temp;


    //Accessing weather data file to read from the start
    ifstream file("Weather.txt"); 
    if (file.is_open()) {
        cout << "You can now access the weather forecast!" << endl;
    }

    file >> info.day;
    file >> info.time;
    file >> info.time_of_day;
    file >> info.current_weather;
    file >> info.temp;

    cout << "Today's weather in Durango, CO is as follows: " << endl;
    cout << "Today is: " << info.day << endl;
    cout << "Current time is: " << Time_Time_of_day::Time_combo(info.time_of_day, info.time) << endl;
    cout << "Current temperature is: " << info.temp << "°F" << endl;
    cout << "It is " << info.current_weather << " outside today." << endl;

    //Try, throw, catch  
    try {
        weatherData info1(day, time, current_weather, time_of_day, temp);
    }
    catch (int e) {
        cout << "Invalid entry. ERROR: " << e << endl;
    }
      
    //Giving the user information on what clothes to wear  
    if (temp <= 25){
        cout << "It is very cold out, I suggest wearing a winter jacket." << endl;
    }
    if (temp > 25 && temp <= 45 ){
        cout << "It is cold out, I suggest wearing a light to medium coat." << endl;
    }
    if (temp > 45 && temp <= 65){
        cout << "It is slightly cold out, I suggest wearing a fleece." << endl;
    }
    if (temp > 65 && temp <= 80){
        cout << "It is warm out, I suggest wearing short sleeves." << endl;
    }
    if (temp > 80){
        cout << "It is hot out, I suggest wearing short sleeves, and to not stay outside too long." << endl;
    }

    file.close();

    return 0;
}
