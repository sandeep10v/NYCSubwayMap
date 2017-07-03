/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sandeep Vuzzini
 *
 * Created on November 30, 2016, 9:31 PM
 */

#include <cstdlib>
#include<stdio.h>
#define INFINITY 2000
#define MAXNODES 357
#define MEMBER 1
#define NONMEMBER 0
#define IN 999
void shortpath(int weight[][MAXNODES], int , int ,int * ,int precede[]);


int main()
{int w,ch,co,precede[357],pd,s,t;
int source, target,x,y;
char *StationNames[357]={"90th St Elmhurst" ,"Fort Hamilton Parkway" ,"207th St" ,"5th Av-53rd St" ,"59th St" ,"Fulton St" ,"45th St" ,"68th St-Hunter College" ,"238th St" ,"Nevins St" ,"Franklin St" ,"Rawson St-33rd St" ,"168th St" ,"Chauncey St" ,"Jefferson St" ,"Aqueduct-North Conduit Av" ,"Sutphin Blvd" ,"182nd-183rd Sts" ,"East 180th St" ,"Beverly Rd" ,"59th St-Columbus Circle" ,"Bowling Green" ,"Times Square" ,"Pelham Parkway" ,"Vernon Blvd-Jackson Av" ,"183rd St" ,"Brook Av" ,"Norwood-205th St" ,"14th St" ,"72nd St" ,"City Hall" ,"Van Siclen Av" ,"East 143rd St-St Mary's St" ,"Grant Av" ,"Montrose Av" ,"Castle Hill Av" ,"Burke Av" ,"28th St" ,"Euclid Av" ,"East Broadway" ,"Lefferts Blvd" ,"104th St-Oxford Av" ,"Forest Parkway-85th St" ,"Nassau Av" ,"36 Av-Washington Av" ,"Atlantic Av" ,"Times Square-42nd St" ,"8th St" ,"163rd St - Amsterdam Av" ,"51st St" ,"Knickerbocker Av" ,"Long Island City-Court Square" ,"95th St" ,"High St" ,"Freeman St" ,"Pelham Bay Park" ,"Broadway Junction-East New York" ,"Saratoga Av" ,"Franklin Av" ,"57th St" ,"Central Av" ,"Kingsbridge Rd" ,"Canal St (UL)" ,"80th St-Hudson St" ,"23rd St-Ely Av" ,"Jackson Av" ,"Queens Plaza" ,"East 105th St" ,"Livonia Av" ,"Yankee Stadium-161st St" ,"111th St" ,"Union Square" ,"8th Av" ,"Intervale Av" ,"14th St-Union Square" ,"190th St" ,"Metropolitan Av" ,"53rd St" ,"Flatbush Av-Brooklyn College" ,"Lowery St-40th St" ,"Queensboro Plaza" ,"Mosholu Parkway" ,"Hoyt & Schermerhorn" ,"Woodhaven Blvd" ,"86th St" ,"Harlem-148th St" ,"Sutphin Blvd-Archer Av - JFK" ,"Eastchester-Dyre Av" ,"110th St-Central Park North" ,"Ditmas Av" ,"4th Av" ,"Beach 90th St" ,"Crescent St" ,"Hewes St" ,"Myrtle-Willoughby Avs" ,"Morris Park" ,"Botanic Gardens" ,"Bronx Park East" ,"Canal St" ,"Inwood - 207th St" ,"168th St - Washington Heights" ,"Myrtle Av" ,"238th St-Nereid Av" ,"176th St" ,"Cypress Av" ,"Dyckman St" ,"215th St" ,"Fresh Pond Rd" ,"30 Av-Grand Av" ,"Baychester Av" ,"Elmhurst Av" ,"Pennsylvania Av" ,"Lexington Av" ,"Beach 44th St" ,"Bay 50th St" ,"Jackson Heights-Roosevelt Ave" ,"Astor Place" ,"Parsons Blvd-Archer Av - Jamaica Center" ,"Far Rockaway-Mott Av" ,"Cathedral Parkway-110th St" ,"175th St" ,"25th St" ,"Borough Hall" ,"Court St" ,"191st St" ,"Beach 25th St" ,"Winthrop St" ,"Rockaway Park-Beach 116th" ,"Chambers St" ,"39 Av-Beebe Av" ,"34th St" ,"9th St" ,"1st Av" ,"104th St-102nd St" ,"Broadway" ,"157th St" ,"Ocean Parkway" ,"East Tremont Av-West Farms Sq" ,"174-175th Sts" ,"45 Rd-Court House Sq" ,"Grand Av-Newtown" ,"Wakefield-241st St" ,"Delancey St" ,"Lafayette Av" ,"49th St" ,"Flushing Av" ,"DeKalb Av" ,"Howard Beach" ,"Smith-9th St" ,"Clark St" ,"Roosevelt Island" ,"21st St" ,"Brighton Beach" ,"West 4th St" ,"Cypress Hills" ,"25th Av" ,"Burnside Av" ,"Bushwick Av" ,"Alabama Av" ,"Graham Av" ,"Van Cortlandt Park-242nd St" ,"Gates Av" ,"Junius St" ,"Utica Av" ,"Rockaway Blvd" ,"Clinton & Washington Avs" ,"Cleveland St" ,"Prospect Park-15 St" ,"Mets - Willets Point" ,"Pacific St" ,"Jay St - Borough Hall" ,"Sterling St" ,"66th St-Lincoln Center" ,"Bergen St" ,"Canarsie - Rockaway Parkway" ,"233rd St" ,"Cortelyou Rd" ,"St Lawrence Av" ,"Broadway-Nassau" ,"Fordham Rd" ,"138th St" ,"Northern Blvd" ,"Kingston Av" ,"Ditmars Blvd" ,"137th St-City College" ,"Broadway-Lafayette St" ,"Jamaica-Van Wyck" ,"46th St" ,"75th Av" ,"Jamaica-179th St" ,"Morgan Av" ,"Astoria Blvd-Hoyt Av" ,"Greenpoint Av" ,"Prospect Park" ,"Buhre Av" ,"Av J" ,"Broad Channel" ,"Av I" ,"Westchester Square-East Tremont Av" ,"Av H" ,"Clinton-Washington Avs" ,"Bedford Av" ,"111th St-Greenwood Av" ,"170th St" ,"Broadway-74th St" ,"Rockaway Av" ,"167th St" ,"225th St" ,"34 St Hudson Yards" ,"77th St" ,"Woodlawn" ,"Dyckman St-200th St" ,"Atlantic Av-Barclays Ctr" ,"Liberty Av" ,"Middletown Rd" ,"110th St" ,"Beach 36th St" ,"Allerton Av" ,"Tremont Av" ,"Lawrence St" ,"9th Av" ,"42nd St" ,"Junction Blvd" ,"174th St" ,"Elderts Lane-75th St" ,"Kew Gardens-Union Turnpike" ,"Sutter Av" ,"79th St" ,"Bliss St-46th St" ,"Bay Parkway" ,"Neptune Av-Van Siclen" ,"Grand Central" ,"121st St" ,"96th St" ,"Carroll St" ,"Brooklyn Bridge-City Hall" ,"47-50th Sts Rockefeller Center" ,"Av X" ,"Av U" ,"Beach 98th St" ,"Rector St" ,"Houston St" ,"Av P" ,"138th St-3rd Ave" ,"Av N" ,"63rd Drive-Rego Park" ,"Av M" ,"Parkside Av" ,"Hunts Point Av" ,"116th St-Columbia University" ,"Lexington Av-53rd St" ,"181st St" ,"5th Av" ,"231st St" ,"82nd St-Jackson Heights" ,"Bowery" ,"Elder Av" ,"20th Av" ,"Beach 67th St" ,"81st St - Museum of Natural History" ,"New Utrecht Av" ,"Marble Hill-225th St" ,"Forest Hills-71st Av" ,"103rd St" ,"155th St" ,"Nostrand Av" ,"East 149th St" ,"Broad St" ,"Parkchester-East 177th St" ,"2nd Av" ,"Aqueduct Racetrack" ,"West 8th St" ,"Morrison Av-Soundview Av" ,"Church Av" ,"18th Av" ,"Bleecker St" ,"Grand St" ,"Wall St" ,"Shepherd Av" ,"World Trade Center" ,"Eastern Parkway-Brooklyn Museum" ,"Newkirk Av" ,"33rd St" ,"Wilson Av" ,"Bedford-Nostrand Avs" ,"145th St" ,"Parsons Blvd" ,"71st St" ,"Hunters Point" ,"67th Av" ,"55th St" ,"Ralph Av" ,"Seneca Av" ,"Christopher St" ,"Simpson St" ,"Neck Rd" ,"149th St-Grand Concourse" ,"6th Av" ,"116th St" ,"Bay Ridge Av" ,"Kosciusko St" ,"Halsey St" ,"88th St-Boyd Av" ,"Classon Av" ,"Grand Army Plaza" ,"Beach 60th St" ,"149th St-3rd Av" ,"South Ferry" ,"Grand Central-42nd St" ,"Union St" ,"York St" ,"36th St" ,"135th St" ,"Zerega Av" ,"Fisk Av-69th St" ,"7th Av" ,"Park Place" ,"Mt Eden Av" ,"Flushing-Main St" ,"Lincoln Av-52nd St" ,"3rd Av" ,"New Lots Av" ,"Lorimer St" ,"18th St" ,"50th St" ,"Kings Highway" ,"Hoyt St" ,"Whitlock Av" ,"Forest Av" ,"Norwood Av" ,"65th St" ,"Briarwood-Van Wyck Blvd" ,"Woodside Av-61st St" ,"Cortlandt St" ,"Bedford Park Blvd" ,"Stillwell Av" ,"Essex St" ,"Sheepshead Bay" ,"Marcy Av" ,"Bedford Park Blvd-Lehman College" ,"Station Name" ,"125th St" ,"Gun Hill Rd" ,"Whitehall St" ,"Steinway St" ,"Spring St" ,"62nd St" ,"219th St" ,"Prospect Av" ,"Bay Parkway-22nd Av" ,"Prince St" ,"Beach 105th St" ,"169th St" ,"President St" ,"Longwood Av" ,"23rd St" ,"Kingston-Throop"};

int redvcpsouth[38][2]={160, 0, 8, 1, 253, 1, 261, 2, 106, 1, 2, 2, 105, 1, 124, 2, 251, 1, 100, 2, 135, 2, 285, 2, 184, 1, 341, 2, 249, 1, 119, 2, 176, 1, 233, 2, 84, 2, 227, 2, 29, 1, 172, 1, 20, 2, 324, 2, 46, 1, 130, 2, 37, 2, 355, 1, 323, 1, 28, 2, 293, 2, 241, 1, 98, 1, 10, 1, 128, 1, 333, 2, 240, 2, 307, 2};
int S_times_square[2][2]= {22, 0, 231, 2}; /* 1. Number of Stations: 2 */
int r_broadway_local[45][2]={262, 0, 289, 2, 245, 2, 83, 2, 140, 1, 110, 1, 115, 1, 330, 3, 181, 2, 187, 3, 344, 3, 311, 2, 66, 2, 112, 2, 252, 1, 59, 2, 144, 2, 42, 1, 130, 2, 37, 1, 355, 1, 74, 2, 47, 1, 350, 1, 98, 1, 30, 2, 333, 2, 240, 2, 343, 2, 123, 3, 170, 3, 146, 3, 212, 4, 309, 1, 90, 1, 348, 1, 121, 1, 216, 2, 6, 1, 77, 2, 4, 1, 299, 2, 209, 3, 84, 2, 52, 3};  /* 2. Number of Stations: 45 */
int m_queen_blvd_6_av_local[36][2]={262, 0, 289, 2, 245, 2, 83, 1, 140, 1, 110, 1, 115, 3, 330, 1, 181, 1, 187, 1, 344, 1, 311, 2, 66, 1, 51, 1, 112, 3, 252, 2, 236, 1, 221, 1, 130, 1, 355, 3, 28, 3, 153, 1, 185, 2, 142, 3, 338, 4, 93, 1, 322, 2, 145, 3, 101, 4, 60, 2, 50, 1, 94, 3, 292, 5, 328, 1, 107, 1, 76, 1}; /* 3. Number of Stations: 36*/
int g_brooklyn_queens_crosstown[21][2]={51, 0, 151, 1, 192, 3, 43, 1, 76, 4, 134, 4, 145, 1, 94, 1, 284, 1, 303, 1, 200, 1, 5, 5, 82, 4, 173, 2, 234, 3, 148, 1, 90, 1, 315, 6, 167, 8, 1, 3, 273, 1}; /* 4. Number of Stations: 21*/
int j_nassau_st_local[30][2]={267, 0, 5, 1, 128, 1, 98, 1, 255, 1, 336, 1, 338, 4, 93, 1, 322, 2, 145, 3, 101, 4, 300, 2, 161, 1, 301, 2, 13, 2, 56, 1, 158, 1, 31, 2, 166, 2, 329, 1, 92, 1, 154, 1, 224, 1, 42, 1, 83, 4, 133, 5, 70, 6, 232, 6, 86, 2, 117, 1};  /* 5. Number of Stations: 30*/
int m_queens_blvd_6_avenue_local[36][2]={262, 0, 289, 2, 245, 2, 83, 1, 140, 1, 110, 1, 115, 3, 330, 1, 181, 1, 187, 1, 344, 1, 311, 2, 66, 1, 51, 1, 112, 3, 252, 2, 236, 1, 221, 1, 130, 1, 355, 3, 28, 3, 153, 1, 185, 2, 142, 3, 338, 4, 93, 1, 322, 2, 145, 3, 101, 4, 60, 2, 50, 1, 94, 3, 292, 5, 328, 1, 107, 1, 76, 1}; /* 6. Number of Stations: 36*/
int n_broadway_exp[39][2]={183, 0, 191, 1, 108, 1, 134, 4, 44, 4, 129, 1, 80, 1, 112, 3, 252, 2, 59, 2, 144, 1, 42, 1, 130, 1, 37, 2, 355, 1, 74, 1, 47, 1, 350, 1, 98, 1, 146, 4, 212, 4, 309, 1, 90, 1, 348, 8, 121, 8, 216, 8, 6, 8, 77, 1, 4, 8, 72, 8, 1, 2, 260, 3, 274, 3, 257, 1, 229 ,1, 325, 2, 238, 1, 84, 1, 335, 2}; /* 7. Number of Stations: 39*/
int q_broadway_exp[30][2]={59, 0, 144, 1, 46, 1, 130, 1, 37, 2, 355, 1, 74, 1, 47, 1, 350, 1, 98, 1, 146, 1, 212, 4, 315, 4, 193, 5, 247, 2, 273, 1, 19, 1, 176, 2, 281, 2, 199, 2, 195, 1, 246, 1, 325, 3, 238, 1, 295, 3, 337, 1, 152, 2, 136, 1, 271, 1, 335, 1}; /* 8. Number of Stations: 30*/
int red2_bronx_to_brooklyn[61][2]={141, 0, 102, 2, 175, 2, 207, 2, 347, 2, 342, 2, 36, 2, 217, 1, 23, 1, 97, 1, 18, 1, 137, 1, 138, 2, 54, 2, 294, 2, 73, 2, 348, 2, 65, 1, 306, 2, 296, 1, 312, 3, 341, 2, 298, 2, 88, 2, 233, 2, 84, 2, 227, 1, 29, 2, 172, 1, 20, 2, 324, 1, 46, 2, 130, 1, 37, 1, 355, 1, 323, 1, 28, 2, 293, 2, 241, 1, 98, 1, 10, 2, 128, 1, 316, 2, 5, 2, 277, 2, 149, 2, 122, 2, 326, 2, 9, 2, 212, 2, 173, 1, 304, 1, 280, 2, 58, 2, 353, 3, 171, 3, 126, 3, 273, 3, 19, 2, 281, 3, 78, 2}; /* 9. Number of Stations: 61*/
int s_franklin_av[4][2]={58, 0, 316, 1, 96, 1, 193, 2}; /* 10. Number of Stations: 4*/
int canarsieLocal14[24][2]={72, 0, 297, 6, 74, 1, 320, 1, 132, 1, 201, 3, 322, 1, 159, 1, 276, 1, 34, 1, 190, 1, 14, 1, 146, 1, 94, 3, 301, 4, 283, 1, 157, 1, 56, 1, 45, 1, 226, 1, 68, 2, 321, 1, 67, 3, 174, 1}; /* 11. Number of Stations: 24*/
int fqueensblvdExp6[45][2]={189, 0, 352, 1, 286, 1, 16, 1, 331, 1, 225, 2, 188, 1, 262, 1, 115, 4, 151, 4, 150, 2, 112, 2, 59, 2, 236, 1, 221, 1, 130, 1, 355, 2, 28, 2, 153, 1, 185, 1, 269, 1, 142, 1, 39, 1, 310, 2, 170, 1, 173, 2, 234, 2, 148, 1, 90, 1, 315, 6, 167, 7, 1, 2, 273, 4, 89, 3, 274, 4, 197, 3, 229, 3, 244, 3, 242, 1, 325, 1, 238, 1, 237, 1, 230, 1, 271, 1, 335, 1}; /* 12. Number of Stations: 45*/
int s_rockway_park_shuttle[66][2]={99, 0, 105, 1, 75, 1, 251, 1, 120, 1, 12, 1, 48, 1, 264, 1, 285, 2, 312, 1, 341, 2, 298, 1, 119, 3, 263, 3, 233, 1, 84, 8, 259, 8, 29, 1, 20, 2, 324, 8, 221, 8, 130, 1, 355, 2, 28, 2, 153, 1, 345, 2, 98, 1, 128, 1, 5, 1, 53, 3, 170, 2, 82, 1, 143, 2, 165, 1, 58, 1, 265, 1, 356, 1, 163, 1, 291, 1, 205, 3, 56, 3, 213, 1, 31, 2, 278, 2, 38, 1, 33, 1, 63, 1, 302, 1, 164, 1, 41, 1, 70, 4, 40, 4, 270, 2, 15, 1, 147, 1, 196, 1, 258, 3, 305, 1, 113, 1, 216, 1, 125, 1, 118, 1, 91, 3, 239, 1, 351, 1, 127, 1}; /* 13. Number of Stations: 66*/
int MtoB3[34][2]={85, 0, 285, 2, 312, 2, 341, 2, 298, 2, 88, 2, 233, 3, 29, 4, 46, 4, 130, 2, 28, 3, 128, 5, 316, 2, 5, 2, 277, 2, 149, 1, 122, 2, 326, 2, 9, 2, 212, 2, 173, 2, 304, 1, 280, 1, 58, 2, 265, 1, 182, 2, 163, 2, 226, 2, 57, 2, 205, 2, 162, 1, 111, 1, 31, 1, 321, 2}; /* 14. Number of Stations: 34*/
int LexAvExp4[54][2]={210, 1, 81, 2, 339, 2, 61, 1, 179, 1, 25, 2, 156, 1, 103, 1, 317, 2, 203, 1, 206, 2, 69, 1, 296, 2, 180, 1, 341, 2, 298, 1, 215, 2, 263, 1, 233, 2, 84, 1, 209, 2, 7, 1, 4, 2, 49, 1, 308, 1, 282, 2, 37, 2, 355, 2, 74, 2, 116, 2, 275, 2, 345, 2, 98, 2, 235, 2, 5, 2, 277, 2, 21, 2, 122, 2, 9, 2, 212, 2, 173, 2, 304, 2, 280, 2, 58, 2, 265, 2, 182, 1, 163, 1, 226, 1, 57, 1, 205, 2, 162, 1, 111, 2, 31, 1, 321, 1}; /* 15. Number of Stations: 54*/
int LexAvExp5[36][2]={87, 0, 109, 2, 342, 2, 23, 2, 95, 2, 18, 2, 137, 2, 223, 2, 54, 2, 294, 2, 73, 2, 348, 2, 65, 2, 306, 3, 296, 2, 180, 2, 341, 2, 84, 3, 4, 2, 308, 3, 74, 2, 235, 2, 5, 2, 277, 2, 21, 3, 122, 2, 9, 2, 212, 2, 58, 3, 353, 2, 171, 3, 126, 2, 273, 2, 19, 2, 281, 3, 78, 2}; /* 16. Number of Stations: 36*/
int LexAvLocal6[38][2]={23, 1, 194, 2, 214, 1, 198, 2, 313, 1, 35, 2, 268, 2, 177, 1, 272, 1, 256, 2, 327, 2, 248, 2, 354, 1, 266, 1, 32, 1, 104, 2, 26, 1, 243, 2, 341, 2, 298, 1, 215, 2, 263, 2, 233, 2, 84, 2, 209, 2, 7, 1, 4, 1, 49, 2, 308, 2, 282, 2, 37, 2, 355, 1, 74, 1, 116, 2, 275, 1, 345, 1, 98, 2, 235, 2}; /* 17. Number of Stations: 38*/
int PelhamBayPkExp6[29][2]={23, 1, 194, 2, 214, 1, 198, 2, 313, 1, 35, 2, 268, 2, 248, 2, 243, 2, 341, 2, 298, 1, 215, 2, 263, 2, 233, 2, 84, 2, 209, 2, 7, 1, 4, 1, 49, 2, 308, 2, 282, 2, 37, 2, 355, 1, 74, 1, 116, 2, 275, 1, 345, 1, 98, 2, 235, 2}; /* 18. Number of Stations: 29*/
int flushingExp7[12][2]={208, 2, 46, 1, 252, 2, 308, 2, 24, 1, 288, 2, 139, 2, 80, 2, 332, 2, 222, 2, 168, 2, 318, 2}; /* 19. Number of Stations: 12*/
int FlushingLocal7[22][2]={208, 2, 46, 1, 252, 2, 308, 2, 24, 1, 288, 2, 139, 2, 80, 2, 11, 1, 79, 2, 228, 1, 319, 2, 332, 2, 314, 1, 204, 1, 254, 2, 0, 2, 222, 2, 263, 1, 70, 1, 168, 2, 318, 2}; /* 20. Number of Stations: 22*/

int i,j,k;
int B[357][357];
 for (i=0;i<357;i++)
        for(j=0;j<357;j++)
            B[i][j]=IN;

/*1. Function to key in the matrix for route Redline VCP south */ 

for(k=0;k<38;k++)
{for (i=0;i<357;i++)
{   if(i==redvcpsouth[k][0])
    for(j=0;j<357;j++)
    {
        if(i==redvcpsouth[k][0] && j==redvcpsouth[k+1][0])
            {B[i][j]=redvcpsouth[k+1][1];
            B[j][i]=redvcpsouth[k+1][1];
            }
    }
}}

/*2. Function to key in the matrix for route S_times_square */ 

for(k=0;k<2;k++)
{for (i=0;i<357;i++)
{   if(i==S_times_square[k][0])
    for(j=0;j<357;j++)
    {
        if(i==S_times_square[k][0] && j==S_times_square[k+1][0])
            {B[i][j]=S_times_square[k+1][1];
            B[j][i]=S_times_square[k+1][1];
            }
    }
}}

/*3. Function to key in the matrix for r_broadway_local */ 

for(k=0;k<45;k++)
{for (i=0;i<357;i++)
{   if(i==r_broadway_local[k][0])
    for(j=0;j<357;j++)
    {
        if(i==r_broadway_local[k][0] && j==r_broadway_local[k+1][0])
            {B[i][j]=r_broadway_local[k+1][1];
            B[j][i]=r_broadway_local[k+1][1];
            }
    }
}}

/*4. Function to key in the matrix for m_queen_blvd_6_av_local*/

for(k=0;k<36;k++)
{for (i=0;i<357;i++)
{   if(i==m_queen_blvd_6_av_local[k][0])
    for(j=0;j<357;j++)
    {
        if(i==m_queen_blvd_6_av_local[k][0] && j==m_queen_blvd_6_av_local[k+1][0])
            {B[i][j]=m_queen_blvd_6_av_local[k+1][1];
            B[j][i]=m_queen_blvd_6_av_local[k+1][1];
            }
    }
}}

/*5. Function to key in the matrix for g_brooklyn_queens_crosstown*/

for(k=0;k<21;k++)
{for (i=0;i<357;i++)
{   if(i==g_brooklyn_queens_crosstown[k][0])
    for(j=0;j<357;j++)
    {
        if(i==g_brooklyn_queens_crosstown[k][0] && j==g_brooklyn_queens_crosstown[k+1][0])
            {B[i][j]=g_brooklyn_queens_crosstown[k+1][1];
            B[j][i]=g_brooklyn_queens_crosstown[k+1][1];
            }
    }
}}

/*6. Function to key in the matrix for j_nassau_st_local*/

for(k=0;k<30;k++)
{for (i=0;i<357;i++)
{   if(i==j_nassau_st_local[k][0])
    for(j=0;j<357;j++)
    {
        if(i==j_nassau_st_local[k][0] && j==j_nassau_st_local[k+1][0])
            {B[i][j]=j_nassau_st_local[k+1][1];
            B[j][i]=j_nassau_st_local[k+1][1];
            }
    }
}}

/*7. Function to key in the matrix for m_queens_blvd_6_avenue_local */

for(k=0;k<36;k++)
{for (i=0;i<357;i++)
{   if(i==m_queen_blvd_6_av_local[k][0])
    for(j=0;j<357;j++)
    {
        if(i==m_queen_blvd_6_av_local[k][0] && j==m_queen_blvd_6_av_local[k+1][0])
            {B[i][j]=m_queen_blvd_6_av_local[k+1][1];
            B[j][i]=m_queen_blvd_6_av_local[k+1][1];
            }
    }
}}

/*8. Function to key in the matrix for n_broadway_exp */

for(k=0;k<39;k++)
{for (i=0;i<357;i++)
{   if(i==n_broadway_exp[k][0])
    for(j=0;j<357;j++)
    {
        if(i==n_broadway_exp[k][0] && j==n_broadway_exp[k+1][0])
            {B[i][j]=n_broadway_exp[k+1][1];
            B[j][i]=n_broadway_exp[k+1][1];
            }
    }
}}

/*9. Function to key in the matrix for q_broadway_exp */

for(k=0;k<30;k++)
{for (i=0;i<357;i++)
{   if(i==q_broadway_exp[k][0])
    for(j=0;j<357;j++)
    {
        if(i==q_broadway_exp[k][0] && j==q_broadway_exp[k+1][0])
            {B[i][j]=q_broadway_exp[k+1][1];
            B[j][i]=q_broadway_exp[k+1][1];
            }
    }
}}

/*10. Function to key in the matrix for red2_bronx_to_brooklyn */

for(k=0;k<61;k++)
{for (i=0;i<357;i++)
{   if(i==red2_bronx_to_brooklyn[k][0])
    for(j=0;j<357;j++)
    {
        if(i==red2_bronx_to_brooklyn[k][0] && j==red2_bronx_to_brooklyn[k+1][0])
            {B[i][j]=red2_bronx_to_brooklyn[k+1][1];
            B[j][i]=red2_bronx_to_brooklyn[k+1][1];
            }
    }
}}

/*11. Function to key in the matrix for s_franklin_av */

for(k=0;k<4;k++)
{for (i=0;i<357;i++)
{   if(i==s_franklin_av[k][0])
    for(j=0;j<357;j++)
    {
        if(i==s_franklin_av[k][0] && j==s_franklin_av[k+1][0])
            {B[i][j]=s_franklin_av[k+1][1];
            B[j][i]=s_franklin_av[k+1][1];
            }
    }
}}

/*12. Function to key in the matrix for canarsieLocal14 */

for(k=0;k<24;k++)
{for (i=0;i<357;i++)
{   if(i==canarsieLocal14[k][0])
    for(j=0;j<357;j++)
    {
        if(i==canarsieLocal14[k][0] && j==canarsieLocal14[k+1][0])
            {B[i][j]=canarsieLocal14[k+1][1];
            B[j][i]=canarsieLocal14[k+1][1];
            }
    }
}}

/*13. Function to key in the matrix for fqueensblvdExp6 */

for(k=0;k<45;k++)
{for (i=0;i<357;i++)
{   if(i==fqueensblvdExp6[k][0])
    for(j=0;j<357;j++)
    {
        if(i==fqueensblvdExp6[k][0] && j==fqueensblvdExp6[k+1][0])
            {B[i][j]=fqueensblvdExp6[k+1][1];
            B[j][i]=fqueensblvdExp6[k+1][1];
            }
    }
}}

/*14. Function to key in the matrix for s_rockway_park_shuttle */

for(k=0;k<66;k++)
{for (i=0;i<357;i++)
{   if(i==s_rockway_park_shuttle[k][0])
    for(j=0;j<357;j++)
    {
        if(i==s_rockway_park_shuttle[k][0] && j==s_rockway_park_shuttle[k+1][0])
            {B[i][j]=s_rockway_park_shuttle[k+1][1];
            B[j][i]=s_rockway_park_shuttle[k+1][1];
            }
    }
}}

/*15. Function to key in the matrix for MtoB3 */

for(k=0;k<34;k++)
{for (i=0;i<357;i++)
{   if(i==MtoB3[k][0])
    for(j=0;j<357;j++)
    {
        if(i==MtoB3[k][0] && j==MtoB3[k+1][0])
            {B[i][j]=MtoB3[k+1][1];
            B[j][i]=MtoB3[k+1][1];
            }
    }
}}

/*16. Function to key in the matrix for LexAvExp4 */

for(k=0;k<54;k++)
{for (i=0;i<357;i++)
{   if(i==LexAvExp4[k][0])
    for(j=0;j<357;j++)
    {
        if(i==LexAvExp4[k][0] && j==LexAvExp4[k+1][0])
            {B[i][j]=LexAvExp4[k+1][1];
            B[j][i]=LexAvExp4[k+1][1];
            }
    }
}}

/*17. Function to key in the matrix for LexAvExp5 */

for(k=0;k<36;k++)
{for (i=0;i<357;i++)
{   if(i==LexAvExp5[k][0])
    for(j=0;j<357;j++)
    {
        if(i==LexAvExp5[k][0] && j==LexAvExp5[k+1][0])
            {B[i][j]=LexAvExp5[k+1][1];
            B[j][i]=LexAvExp5[k+1][1];
            }
    }
}}

/*18. Function to key in the matrix for LexAvLocal6 */

for(k=0;k<38;k++)
{for (i=0;i<357;i++)
{   if(i==LexAvLocal6[k][0])
    for(j=0;j<357;j++)
    {
        if(i==LexAvLocal6[k][0] && j==LexAvLocal6[k+1][0])
            {B[i][j]=LexAvLocal6[k+1][1];
            B[j][i]=LexAvLocal6[k+1][1];
            }
    }
}}

/*19. Function to key in the matrix for PelhamBayPkExp6 */

for(k=0;k<29;k++)
{for (i=0;i<357;i++)
{   if(i==PelhamBayPkExp6[k][0])
    for(j=0;j<357;j++)
    {
        if(i==PelhamBayPkExp6[k][0] && j==PelhamBayPkExp6[k+1][0])
            {B[i][j]=PelhamBayPkExp6[k+1][1];
            B[j][i]=PelhamBayPkExp6[k+1][1];
            }
    }
}}

/*20. Function to key in the matrix for flushingExp7 */

for(k=0;k<12;k++)
{for (i=0;i<357;i++)
{   if(i==flushingExp7[k][0])
    for(j=0;j<357;j++)
    {
        if(i==flushingExp7[k][0] && j==flushingExp7[k+1][0])
            {B[i][j]=flushingExp7[k+1][1];
            B[j][i]=flushingExp7[k+1][1];
            }
    }
}}

/*20. Function to key in the matrix for FlushingLocal7 */

for(k=0;k<22;k++)
{for (i=0;i<357;i++)
{   if(i==FlushingLocal7[k][0])
    for(j=0;j<357;j++)
    {
        if(i==FlushingLocal7[k][0] && j==FlushingLocal7[k+1][0])
            {B[i][j]=FlushingLocal7[k+1][1];
            B[j][i]=FlushingLocal7[k+1][1];
            }
    }
}}

    for (i=0;i<10;i++)
        {for(j=0;j<10;j++)
           printf("%d ",B[i][j]);
        printf("\n");
        }

/* printf("\n Enter the starting node and the ending node: ");
   scanf(" %d %d",&s,&t);*/

   printf("\n Enter the starting station id: ");
   scanf("%d", &s);
   printf("\n Enter the destination station id: ");
   scanf("%d", &t);
   shortpath(B,s,t,&pd,precede);
   printf("\n The shortest distance to reach from source station %d to destination station %d is [Note: I have not considered your walking speed]: %d min",s,t,pd);


 return 0;
}

void shortpath(int weight[][MAXNODES],int s, int t, int *pd, int precede[])
{
  int distance[MAXNODES],perm[MAXNODES];
  int current,i,j,k,dc;
  int smalldist,newdist;
  /* initialization of perm and distance array */
  for(i=0;i<MAXNODES;i++)
  {
   perm[i]=NONMEMBER;
   distance[i]=INFINITY;
  }
  perm[s] = MEMBER;
  distance[s] = 0;
  current = s;
  while(current != t)
  {
   smalldist=INFINITY;
   dc=distance[current];
   for(i=0;i<MAXNODES;i++)
     if(perm[i]==NONMEMBER)
     {
      newdist = dc + weight[current][i];
      if(newdist < distance[i])
      {
       distance[i]=newdist;
       precede[i]=current;
      }
      if(distance[i] < smalldist)
      {
       smalldist = distance[i];
       k=i;
      }
    } /* end of for if */
    current = k;
    perm[current]=MEMBER;
   }  /* END WHILE */
   *pd=distance[t];
}