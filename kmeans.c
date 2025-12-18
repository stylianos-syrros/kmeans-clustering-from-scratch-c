#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define M 12

struct examples
{
  float x;
  float y;
};

struct team
{
  float dist;
  int num_of_team;
};

struct examples array[1200];//array with the examples


void openFile()
{
  int array_counter=0;//index of position
  float x1;
  float x2;
  FILE *fp=fopen("examplesSDO.txt","r");
  if(fp==NULL)
  {
    printf("The file with the examples couldn't open\n");
    exit(1);
  }
  while(fscanf(fp,"%f %f",&x1,&x2)!=EOF) //read the whole file
  {
    array[array_counter].x=x1;
    array[array_counter].y=x2;
    array_counter++;
  }
  fclose(fp); //close file
  printf("The file closed\n");
}

void printArray(struct examples array1[])
{
  for(int i=0;i<1200;i++)
  {
    printf("Position: %d x: %f y:%f \n",i,array[i].x,array[i].y);
  }
}


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}



void k_means_algorithm()
{
  float distance;
  int iterations=0;
  int upper=1199;
  int lower=0;
  float square_root=0;
  int check=1;
  srand(time(NULL));

  int initial_centroids [M];//periexei tous tyxaious ari8mous
  int positions[M];
  struct examples w_centers[M];//last iteration coordinates of centroids
  struct team arr[1200][M];//pinakas gia tis apostaseis  [[(apostash,omada0),(apostash,omada1),(apostash,omada2)]] Example0
  struct examples teams[M][1200];//diaxwrismos paradeigmatwn se omades  [[(X1,Y1),(X2,Y2),(X3,Y3)] --->omada1]

  struct examples w_centers_new[M];//current iteration coordinates of centroids

  int helpArray[M];
  int last_positions[M];
  //centroids random generation and initialization
  for(int i=0;i<M;i++)
  {
    initial_centroids[i]=(rand()%(upper- lower+1)) +lower;
    w_centers[i].x=array[initial_centroids[i]].x;
    w_centers[i].y=array[initial_centroids[i]].y;
  }
  //initialization of num_of_elements of each team and the the new_centroids
  for(int i=0;i<M;i++)
  {
    positions[i]=0;
    w_centers_new[i].x= w_centers[i].x;
    w_centers_new[i].y= w_centers[i].y;
  }
  //k-means algorithm
  while(iterations<300)
  {
    check=0;
    printf("--------------------%d----------------------------\n",iterations);
    //STEP:1 Euclidian distance calculation of each example from the centers and put the Example to a team
    for(int i=0;i<1200;i++)
    {
      //for each team
      for(int j=0;j<M;j++)
      {
        distance=pow((array[i].x - w_centers[j].x),2) + pow((array[i].y - w_centers[j].y),2);//riza (x1-x2)^2 + (y1-y2)^2
        square_root=sqrt(distance);
        arr[i][j].dist=square_root;
        arr[i][j].num_of_team=j;
      }
      //sorting the distances
      qsort(arr[i],M,sizeof(struct team),cmpfunc);
      int team,counter;
      team=arr[i][0].num_of_team; //minimum distance for this example
      counter=positions[team]; // right position to put the example
      //put the example to the right team
      teams[team][counter].x=array[i].x;
      teams[team][counter].y=array[i].y;
      positions[team]++; //position update
    }
    //print messages
    for(int i=0;i<M;i++)
    {
      printf("Position:%d for the team:%d\n",positions[i],i);
    }
    for(int i=0;i<M;i++)
    {
      printf("The old centers are:%f,%f\n",w_centers[i].x,w_centers[i].y);
    }
    //STEP 2:Centers_Update(Average of each team)
    for(int i=0;i<M;i++)
    {
      float new_center_x=0;
      float new_center_y=0;
      for(int j=0;j<positions[i];j++)
      {
        new_center_x+= teams[i][j].x;
        new_center_y+= teams[i][j].y;
      }
      if(positions[i]==0) //an den mphke kanena sthn sygkekrimenh omada (division by zero)
      {
        w_centers_new[i].x=w_centers[i].x;
        w_centers_new[i].y=w_centers[i].y;
      }
      else
      {
        w_centers_new[i].x= (float)new_center_x/positions[i];
        w_centers_new[i].y= (float)new_center_y/positions[i];
      }
    }
    //TERMINATION PHASE --check if the centroids centers have changed
    //initialization of helpArray
    for(int i=0;i<M;i++)
    {
      helpArray[i]=0;
    }
    for(int i=0;i<M;i++)
    {
      if(w_centers_new[i].x==w_centers[i].x && w_centers_new[i].y==w_centers[i].y)
      {
        helpArray[i]=1; //1 -->same values , 0-->different values
      }
    }
    for(int i=0;i<M;i++) //clearUp the Positions Counter and Update the centers
    {
      w_centers[i].x= w_centers_new[i].x;
      w_centers[i].y= w_centers_new[i].y;
      last_positions[i]=positions[i];
      positions[i]=0;
    }
    for(int i=0;i<M;i++)
    {
      printf("The new centers are:%f,%f\n",w_centers[i].x,w_centers[i].y);
    }
    //[1,1,1]-->stop , [0,0,1]->next iteration
    for(int i=0;i<M;i++)
    {
      if(helpArray[i]==0)//estw mia diaforetikh -->nea epanalhpsh
      {
        check=1;
        break;
      }
    }
    if(check==0)
    {
      break;
    }
    iterations++;// num_of_iterations update
  }
  //end of while
  printf("Iterations:%d\n",iterations);
  float sum=0;
  //Team_Error_Calculation
  for(int i=0;i<M;i++)
  {
    for(int j=0;j<last_positions[i];j++)
    {
      distance=pow((teams[i][j].x - w_centers[i].x),2) + pow((teams[i][j].y - w_centers[i].y),2);
      square_root=sqrt(distance);
      sum+=square_root;
    }
  }
  printf("The total team error is:%f \n",sum);
  //put the teams in a txt file
  FILE * fp1=fopen("teams_data.txt","w");
  if(fp1==NULL)
  {
    printf("Error1!\n");
    exit(2);
  }
  for(int i=0;i<M;i++)
  {
    for(int j=0;j<last_positions[i];j++)
    {
      fprintf(fp1, "%d %f %f\n",i,teams[i][j].x,teams[i][j].y);
    }
  }
  fclose(fp1);
  //txt file for the centers
  FILE *fp2=fopen("centers_data.txt","w");
  if(fp2==NULL)
  {
    printf("Error2!\n");
    exit(3);
  }
  for(int i=0;i<M;i++)
  {
    fprintf(fp2,"%f %f\n",w_centers_new[i].x,w_centers_new[i].y);
  }
  fclose(fp2);
}


int main()
{
  openFile();
  k_means_algorithm();
  system("python script.py");
  return 0;
}
