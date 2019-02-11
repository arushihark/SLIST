//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */


#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void mergeSort(slist* arr, int l,int r);
void merge(slist* arr, int l, int m, int r);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[150] ;
    slist* airportArr = new slist();
    //Airport* airportArr[13500];			// Replace array with Linked List
    //int airportCount;
    //Airport* a[13500];

    infile.open ("./airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
        int c=0;
        infile.getline(cNum, 256, '\n');
        while (infile.good())
        {
            Airport* currentAirport = new Airport();
            infile.getline(currentAirport->code, 256, ',');
            infile.getline(currentAirport->type, 256, ',');
            infile.getline(currentAirport->name, 256, ',');
            infile.getline(cNum, 256, ',');
            currentAirport->longitude = atof(cNum);
            infile.getline(cNum, 256, ',');
            currentAirport->latitude = atof(cNum);
            infile.getline(cNum, 256, ',');
            currentAirport->elevation = atof(cNum);
            infile.getline(currentAirport->continent, 256, ',');
            infile.getline(currentAirport->isoCountry, 256, ',');
            infile.getline(currentAirport->isoRegion, 256, ',');
            infile.getline(currentAirport->municipality, 256, ',');
            infile.getline(currentAirport->gpsCode, 256, ',');
            infile.getline(currentAirport->iataCode, 256, ',');
            infile.getline(currentAirport->localCode, 256, '\n');
            airportArr->add(*currentAirport);
            //cout << "CODEEE: " << currentAirport->code << endl;
            i++;
            c++;

            //currentAirport->toString();
        }
        //airportCount = c-1;
        infile.close();

    }
    else
    {
        cout << "Error opening file";
    }
    //within 100 miles code
    cout << "AIRPORTS WITHIN 100 MILES OF AUSTIN AIRPORT" << endl;
    for (int i = 0; i < airportArr->length; i++) {
        //assigning lat and long to curr airport
        Airport currAirport = airportArr->get(i);
        double currAirportLat = currAirport.latitude;
        double currAirportLong = currAirport.longitude;
        //getting distance between airports
        double distance = distanceEarth(currAirportLat,currAirportLong,97.6664,30.1975);
        if (distance < 160.934) {
            string code = currAirport.code;
            double longg = currAirport.longitude;
            double latt = currAirport.latitude;
            //string continentt = currAirport.continent;
            cout << "CODE: " << code << " LONGITUDE: " << longg << " LATITUDE: " << latt << endl;
        }
        if (distance > 8800) {
            string code = currAirport.code;
            //cout << "DIS IS ABOVE 1398....... " << "CODE: " << code << " DISTANCE " << distance << endl;
        }
    }
    mergeSort(airportArr,0,airportArr->length-1);

    //cout << "SORTED ARRAY: " << endl;
    //airportArr->toString();

}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/

void merge(slist* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    slist* L = new slist();
    slist* R = new slist();


    for (i = 0; i < n1; i++){
        L->get(i) = arr->get(l + i);
    }
    for (j = 0; j < n2; j++) {
      R->get(j) = arr->get(m + 1 + j);
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){

        if ( distanceEarth(L->get(i).latitude, L->get(i).longitude, 30.1975, 97.6664) <= distanceEarth( R->get(j).latitude, R->get(j).longitude, 30.1975, 97.6664 )){
            arr->get(k) = L->get(i);
            i++;
        }
        else
        {
            arr->get(k) = R->get(j);
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr->get(k) = L->get(i);
        i++;
        k++;
    }


    while (j < n2){
        arr->get(k) = R->get(j);
        j++;
        k++;
    }
}

void mergeSort(slist* arr, int l, int r) {
    if (l < r) {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


