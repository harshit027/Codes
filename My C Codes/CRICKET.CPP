 /*operations on class cricket :HARSHIT  */
 #include"iostream.h"
 #include"conio.h"
 #include"string.h"
 class cricket
 {
 private:
 char plrname[20],tmname[20];
 float batavg;
 public:
 cricket(){cout<<"\nconstructor called : ";}
 ~cricket(){cout<<"\ndestructor called : ";}
 void setname(char n[20])
 {
 int i;
 cout<<"\nenter name of player : ";
 cin>>n;
 strcpy(plrname,n);
 }
 void setteam(char t[20])
 {
 int i;
 cout<<"\nenter team name : ";
 cin>>t;
 strcpy(tmname,t);
 }
 void setbatavg(float b)
 {
 cout<<"\nenter the batting avg : ";
 cin>>b;
 batavg=b;
 }
 float getbatavg() const {return batavg;}
 float display(){return batavg;}
 };
 void main()
 {
 clrscr();
 int i;
 char name[20],teamname[20];
 float batavg=0;
 cricket player[2];
 for(i=0;i<2;i++)
 {
 player[i].setname(name);
 player[i].setteam(teamname);
 player[i].setbatavg(batavg);
 cout<<"\nname of player "<<i<<": "<<name;
 batavg=player[i].display();
 cout<<"\nbatting avg of player : "<<batavg;
 }
 getch();
 }
