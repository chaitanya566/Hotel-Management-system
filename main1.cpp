//g++ main1.cpp -o main1
//./main1
#include<iostream>
#include<string>
#include <conio.h> 
#include <stdlib.h>
using namespace std;
void enter_key_to_start();
void nfloorf(int *nfloor,int *nroom);
bool nroomf(int *nfloor,int *nroom);
void confirm_nroom_nfloor(int *nfloor,int *nroom);
void finalize_hotel(int *nfloor,int *nroom);
void book_floor(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void book_room(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void confirm_room_values(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void set_hotel_values(int *nfloor,int *nroom,char ***hotel);
void hotel_booking(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void redo_booking(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void book_features(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void check_features(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
void finalize_features(int *nfloor,int *nroom,int *floor,int *room,char ***hotel);
int main(){
    int *nfloor = new int;
    int *nroom = new int;
    int *floor = new int;
    int *room = new int;
    system("cls");
    enter_key_to_start();  
    nfloorf(nfloor,nroom);
    system("cls");
    confirm_nroom_nfloor(nfloor,nroom);
    //part 1 done
    char ***hotel = new char**[*nfloor];
    for (int i = 0; i < *nfloor; i++) {
        hotel[i] = new char*[*nroom];
        for (int j = 0; j < *nroom; j++) {
            hotel[i][j] = new char[11];
        }
    }
    set_hotel_values(nfloor,nroom,hotel);
    book_floor(nfloor,nroom,floor,room,hotel);
    finalize_features(nfloor,nroom,floor,room,hotel);
    delete nfloor;
delete nroom;
delete floor;
delete room;

// Also, don't forget to delete memory for the hotel array
for (int i = 0; i < *nfloor; i++) {
    for (int j = 0; j < *nroom; j++) {
        delete[] hotel[i][j];
    }
    delete[] hotel[i];
}
delete[] hotel;
return 0;
    
}
void enter_key_to_start(){
    cout<< "\033[1m" << "Hotel Project" << "\033[0m" <<endl;
    std::cout << "Press any key to start the following application...." << std::endl;
    while (!_kbhit()) {} // Wait for user input
    _getch(); // Clear the key buffer
}
void nfloorf(int *nfloor,int *nroom){
    system("cls");
    int rough=0;
    string value_string;
    while(true){
        while(true){
        system("cls");
        cout<<"Enter the"<< "\033[1m" << " Number of floors " << "\033[0m" <<"that are present in the hotel"<<endl;
        cout << "Enter a" << "\033[1m" << " integer value" << "\033[0m" << " : ";
        getline(std::cin, value_string);
    
    try {
            *nfloor = stoi(value_string);
            break;
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
                cout<<"Enter the"<< "\033[1m" << " Number of floors " << "\033[0m" <<"that are present in the hotel"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , "<<value_string<< "\033[0m" <<" Please enter a valid integer." << std::endl;
        }
        }

    *nfloor=*nfloor+1;
    if (nroomf(nfloor,nroom)){
        break;
    }
    else{
        
        continue;
    }
    }
    return;
}
bool nroomf(int *nfloor,int *nroom){
    system("cls");
    string value_string;
    int rough=0;
    cout<<"The" << "\033[1m" << " Number of floors " << "\033[0m" << "present in the hotel are "<<*nfloor-1<<endl;
    cout<<"You can enter " << "\033[1m" << "'back' " << "\033[0m" << "to change the value of" << "\033[1m" << " 'Number of floors' " << "\033[0m" <<endl;
    cout<<"Enter the" << "\033[1m" << " Number of rooms " << "\033[0m" <<  "per floor that are present in the hotel"<<endl;
    while (true){
    cout << "Enter a" << "\033[1m" << " integer value" << "\033[0m" << " : ";
    getline(std::cin, value_string);
    if (value_string=="back"){
        return false;
    }
    else{
        try {
            
            *nroom = stoi(value_string);
            *nroom=*nroom+1;
            break;
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
                cout<<"The" << "\033[1m" << " Number of floors " << "\033[0m" << "present in the hotel are "<<*nfloor-1<<endl;
                cout<<"You can enter " << "\033[1m" << "'back' " << "\033[0m" << "to change the value of" << "\033[1m" << " 'Number of floors' " << "\033[0m" <<endl;
                cout<<"Enter the" << "\033[1m" << " Number of rooms " << "\033[0m" <<  "per floor that are present in the hotel"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " <<value_string << "\033[0m" <<" Please enter a valid integer." << std::endl;
        }
    }
  return true;
    }
}
void confirm_nroom_nfloor(int *nfloor,int *nroom){
    system("cls");
    cout<<"Before proceding any further" << "\033[1m" << " Please check the values " << "\033[0m" <<  "of the number of floor and as well the rooms per floor"<<endl;
    cout<<"If you proceeded with the wrong values from this point on."<<endl;
    cout<<"You have to" << "\033[1m" << " Restart the whole programme " << "\033[0m"<<endl;
    cout<<"The values you have inputed are : "<<endl;
    cout<<"The" << "\033[1m" << " Number of floors " << "\033[0m" <<  " in this hotel are : "<<*nfloor-1<<endl;
    cout<<"The"<< "\033[1m" << " Number of Rooms per floor " << "\033[0m" << "in this hotel are : "<<*nroom-1<<endl;
    string value_string;
    int rough=0;
      while (true) {
        cout<<"To proceed with the inputed values {number of floors and rooms per floor} , Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " or to change the values input " << "\033[1m" << "'no' " << "\033[0m" << " ONLY"<<endl;
        cout << "Enter a" << "\033[1m" << " value" << "\033[0m" << " : ";
        getline(std::cin, value_string);

        try {
            if (value_string=="yes"){
                finalize_hotel(nfloor,nroom);
                break;
            }
             if (value_string=="no"){
                nfloorf(nfloor,nroom);
            }
            
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
               cout<<"To proceed with the inputed values {number of floors and rooms per floor} , Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " or to change the values input " << "\033[1m" << "'no' " << "\033[0m" << " ONLY"<<endl;
                rough=0;
            }
           cout  << "\033[1m" << "Invalid value , " << "\033[0m" <<" Please enter a valid value('yes' or 'no') " << std::endl;
        }
    }
}

void finalize_hotel(int *nfloor,int *nroom){
    system("cls");
    cout<<"you have created a hotel with "<<*nfloor-1<< "\033[1m" << " floors " << "\033[0m" << "and "<<*nroom-1<< "\033[1m" << " rooms per floor " << "\033[0m" << endl;
    cout<<"if you want to change these values you gotta" << "\033[1m" << "restart the programme " << "\033[0m" <<endl;
    cout<<"to continue you booking experience " << "\033[1m" << ", Press any key to continue" << "\033[0m" <<endl;
    while (!_kbhit()) {} 
    _getch();
}
void book_floor(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    system("cls");
    string value_string;
    cout<<"Enter the"<< "\033[1m" << " Floor " << "\033[0m" <<"that you want to book your room in "<<endl;
    int rough=0;
      while (true) {
        cout << "Enter a" << "\033[1m" << " integer value" << "\033[0m" <<"between [0 - "<<(*nfloor)-1<< "]  : ";
        getline(std::cin, value_string);

        try {
            
            *floor = stoi(value_string);
            if (*floor>=0 && *floor<*nfloor){
            break;
            }
            else{
                cout<<"the floor you have entered " <<*floor <<" does not exist please enter the value again within the range [ 0 -"<<*nfloor-1<< "]  : "<<endl;
                continue;
            }
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
                cout<<"Enter the"<< "\033[1m" << " Floor " << "\033[0m" <<"that you want to book your room in "<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " << "\033[0m" <<" Please enter a valid integer." << std::endl;
        }
    }
    book_room(nfloor,nroom,floor,room,hotel);
    return;
}
void book_room(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){

   system("cls");
    string value_string;
    cout<<"The" << "\033[1m" << " Floors " << "\033[0m" << "in which you are going to book is "<<*floor<<endl;
    cout<<"You can enter " << "\033[1m" << "'back' " << "\033[0m" << "to change" << "\033[1m" << " 'Floors' " << "\033[0m"<<"in which you were going to book in" <<endl;
    cout<<"Enter the" << "\033[1m" << " Room " << "\033[0m" <<  "you going to book, its in the range [ 0 - "<<*nroom-1<<" ]"<<endl;
    int rough=0;
      while (true) {
        cout << "Enter a" << "\033[1m" << " integer value" << "\033[0m" << " : ";
        getline(std::cin, value_string);
    if (value_string=="back"){
        book_floor(nfloor,nroom,floor,room,hotel);
    }
        try {
            
            *room = stoi(value_string);
           if (*room>=0 && *room<*nroom ){
            break;
            }
            else{
                cout<<"the room you have entered " << room <<" does not exist please enter the value again within the range [ 0 -"<<*nroom-1<< "]  : "<<endl;
                continue;
            }
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
                cout<<"The" << "\033[1m" << " Number of floors " << "\033[0m" << "present in the hotel are "<<*nfloor-1<<endl;
                cout<<"You can enter " << "\033[1m" << "'back' " << "\033[0m" << "to change the value of" << "\033[1m" << " 'Number of floors' " << "\033[0m" <<endl;
                cout<<"Enter the" << "\033[1m" << " Number of rooms " << "\033[0m" <<  "per floor that are present in the hotel"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " <<value_string << "\033[0m" <<" Please enter a valid integer." << std::endl;
        }
    }
    confirm_room_values(nfloor,nroom,floor,room,hotel);
    return;
    
}
void confirm_room_values(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    system("cls");
    cout<<"The values you have inputed are : "<<endl;
    cout<<"The" << "\033[1m" << "  Floor " << "\033[0m" <<  " in which you booked is : "<<*floor<<endl;
    cout<<"The"<< "\033[1m" << " Rooms " << "\033[0m" << "in which you booked is : "<<*room<<endl;
    cout<<"are you sure this is the room you want to book? "<<endl;


    string value_string;
    int rough=0;
      while (true) {
        cout<<"To proceed with the inputed values {the room details} , Input" << "\033[1m" << "'yes' " << "\033[0m" <<  "  to change the values input " << "\033[1m" << "'no' " << "\033[0m" << " ONLY"<<endl;
        cout << "Enter a" << "\033[1m" << " value" << "\033[0m" << " : ";
        getline(std::cin, value_string);

        try {
            if (value_string=="yes"){
                hotel_booking(nfloor,nroom,floor,room,hotel);
                break;
            }
             if (value_string=="no"){
                book_floor(nfloor,nroom,floor,room,hotel);
            }
            
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
              cout<<"To proceed with the inputed values {the room details} , Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " or to change the values input " << "\033[1m" << "'no' " << "\033[0m" << " ONLY"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " << "\033[0m" <<" Please enter a valid value('yes' or 'no' only) " << std::endl;
        }
    }
    return;
}
void set_hotel_values(int *nfloor,int *nroom,char ***hotel){
    for(int i=0;i<*nfloor;i++){
        for(int j=0;j<*nroom;j++){
            for(int k=0;k<11;k++){
                hotel[i][j][k]='0';
            }
        }
    }
    return;
}
// << "\033[1m" << "extra features " << "\033[0m" << 
void hotel_booking(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    system("cls");
    hotel[*floor][*room][0]='1';
    cout<<"You have successfully booked the room "<<floor<< "\033[1m" << "Floor " << "\033[0m" << room<< "\033[1m" << " Room " << "\033[0m" << endl;
    cout<<"do you wish to add" << "\033[1m" << " extra facilities " << "\033[0m" <<  "or" << "\033[1m" << " extra features " << "\033[0m" <<  " to your booked room?"<<endl;
    system("cls");
    string value_string;
    int rough=0;
      while (true) {
        cout<<"Input" << "\033[1m" << "'yes' " << "\033[0m" <<  "  to add " << "\033[1m" << " extra facilities " << "\033[0m" <<  "or" << "\033[1m" << " extra features " << "\033[0m" <<  "  to your booked room or " << "\033[1m" << "'no' " << "\033[0m" << " to skip this process"<<endl;
        cout << "Enter a" << "\033[1m" << " value" << "\033[0m" << " : ";
        getline(std::cin, value_string);

        try {
            if (value_string=="yes"){
                book_features(nfloor,nroom,floor,room,hotel);
               
                break;
            }
             if (value_string=="no"){
                redo_booking(nfloor,nroom,floor,room,hotel);
                break;//?
            }
            
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
               cout<<"Input" << "\033[1m" << "'yes' " << "\033[0m" <<  "  to add " << "\033[1m" << " extra facilities " << "\033[0m" <<  "or" << "\033[1m" << " extra features " << "\033[0m" <<  "  to your booked room or " << "\033[1m" << "'no' " << "\033[0m" << " to skip this process"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " << "\033[0m" <<" Please enter a valid value('yes' or 'no' only) " << std::endl;
        }
    }
    return;
}
void redo_booking(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    system("cls");
    cout<<"You have successfully booked the room!"<<endl;
    cout<<"Do you wish to book more rooms?"<<endl;
    string value_string;
    int rough=0;
      while (true) {
        cout<<" Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " to book more rooms or else " << "\033[1m" << "'no' " << "\033[0m" << " to exit booking"<<endl;
        cout << "Enter a" << "\033[1m" << " value" << "\033[0m" << " : ";
        getline(std::cin, value_string);

        try {
            if (value_string=="yes"){
                book_floor(nfloor,nroom,floor,room,hotel);
                
                break;
            }
             if (value_string=="no"){
                exit(0);
                //------------------------------------------------------------------------
            }
            
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
              cout<<" Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " to book more rooms or else " << "\033[1m" << "'no' " << "\033[0m" << " to exit booking"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " << "\033[0m" <<" Please enter a valid value('yes' or 'no' only) " << std::endl;
        }
    }
}
// << "\033[1m" << "extra features " << "\033[0m" << 
void book_features(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    // int rough1;
    // if (rough1==1){
    //     cout<<"Done!, your cart has been updated"<<endl;
    // }
    // rough1=1;
    // for loop
    int rough=0;
    int feature;
    while (true) {
    system("cls");
    
    cout<<"The" << "\033[1m" << "  Floor " << "\033[0m" <<  " in which you booked is : "<<*floor<<endl;
    cout<<"The"<< "\033[1m" << " Rooms " << "\033[0m" << "in which you booked is : "<<*room<<endl;
    cout<<"The additional facilities and features available in our hotel are "<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"1)"<< "\033[1m" << "Swimming Pool" << "\033[0m" <<endl;
    cout<<"2)"<< "\033[1m" << "Fitness Center" << "\033[0m" <<endl;
    cout<<"3)"<< "\033[1m" << "Dinning Plaza" << "\033[0m" <<endl;
    cout<<"4)"<< "\033[1m" << "Laundry Service" << "\033[0m" <<endl;
    cout<<"5)"<< "\033[1m" << "Conference Room" << "\033[0m" <<endl;
    cout<<"6)"<< "\033[1m" << "Wi-fi" << "\033[0m" <<endl;
    cout<<"7)"<< "\033[1m" << "Spa Services" << "\033[0m" <<endl;
    cout<<"8)"<< "\033[1m" << "Games Area" << "\033[0m" <<endl;
    cout<<"9)"<< "\033[1m" << "Tour Guide Services" << "\033[0m" <<endl;
    cout<<"10)"<< "\033[1m" << "HouseKeeping Services" << "\033[0m" <<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;

    string value_string;
    
    cout<<"Enter "<< "\033[1m" << " 'done' " << "\033[0m" <<" once you have chosen all your facilities/features "<<endl;
    cout<<"Enter the"<< "\033[1m" << " Serial Number " << "\033[0m" <<"that you want to book your facility/feature "<<endl;
    cout<<"Enter the"<< "\033[1m" << " Serial Number " << "\033[0m" <<"once again to cancel your facility/feature "<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    check_features(nfloor,nroom,floor,room,hotel);
    if (rough==1){
        cout  << "\033[1m" << "Invalid value! " << "\033[0m"<< std::endl;
    }
    
        cout << "Enter a" << "\033[1m" << " integer value [1-10]" << "\033[0m" <<endl;
        getline(std::cin, value_string);

        try {
            if (value_string=="done"){
                return;
            }
            feature = stoi(value_string);
            if (feature<11 && feature>0){
                if(hotel[*floor][*room][feature]=='1'){
                    hotel[*floor][*room][feature]='0';
                    rough=0;
                    continue;
                }
                hotel[*floor][*room][feature]='1';
                continue;
                //-------------------------------------------------
            break;
            }
            else{
                cout<<"the Number you have entered " <<feature <<" does not exist please enter the value again within the range [ 1 -10] : "<<endl;
                rough=1;
                continue;
            }
        }
        catch (const std::exception& e) {
            rough=1;
            continue;
            
        }
    }

}
void check_features(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    
    int x=0;
    for(int i=1;i<11;i++){
        if(hotel[*floor][*room][i]=='1'){
            if (x==0){
                cout<<"The booked features/facilities are : ";
                x=1;
            }

            cout<<i<<" ";
        }
       
    }
     if(x==0){
            cout<<"You currently booked no features/facilities try booking some! "<<endl;
        }
    cout<<"\n";
    return;
}
//here
void finalize_features(int *nfloor,int *nroom,int *floor,int *room,char ***hotel){
    system("cls");
    cout<<"Are you sure these are final values?";
    check_features(nfloor,nroom,floor,room,hotel);
    string value_string;
    int rough=0;
      while (true) {
        cout<<" Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " to book your room with the above features/facilities " << "\033[1m" << "'no' " << "\033[0m" << " to redo the features/facilities cart"<<endl;
        cout << "Enter a" << "\033[1m" << " value" << "\033[0m" << " : ";
        getline(std::cin, value_string);

        try {
            if (value_string=="yes"){
                redo_booking(nfloor,nroom,floor,room,hotel);
                return;
                
                break;
            }
             if (value_string=="no"){
                book_features(nfloor,nroom,floor,room,hotel);
               
            }
            
        }
        catch (const std::exception& e) {
            rough=rough+1;
            if (rough==4){
                system("cls");
              cout<<" Input" << "\033[1m" << "'yes' " << "\033[0m" <<  " to book more rooms or else " << "\033[1m" << "'no' " << "\033[0m" << " to exit booking"<<endl;
                rough=0;
            }
            cout  << "\033[1m" << "Invalid value , " << "\033[0m" <<" Please enter a valid value('yes' or 'no' only) " << std::endl;
        }
    }
}
