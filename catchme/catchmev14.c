#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for usleep() function
#include <conio.h> // for getch() function
#include <windows.h>
//#define SLEEP_TIME 500000 // time to sleep between frames in microseconds

//Global Variables 
	struct entry {
		char q[20];
		int ans;
		int num[100];
	};
	struct entry list[100];
	int pos[10][2], score=0, level=1;
	char names[100];
	int SLEEP_TIME=500000; 
FILE *fp;
FILE *flp;
FILE *ques;

void showMainMenu();
void startGame();
void gameOver();
void showAddQuestions();
void showLeaderboards();
void showInstructions();
void showAbout();

//Technicals
int newlineENtab();
void press();
void con();
int selectOPTION();

int main(){
	system("COLOR F0");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	newlineENtab(6, 2);	SetConsoleTextAttribute(h,241); printf(" ‹‹‹‹‹‹‹    ‹‹‹‹‹‹‹‹    ‹‹‹‹‹‹‹‹‹‹‹    ‹‹‹‹‹‹‹   ‹‹‹‹‹  ‹‹‹‹‹   ‹‹‹‹‹   ‹‹‹‹‹   ‹‹‹‹‹‹‹‹"); 
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,241); printf("€€€€€ﬂﬂﬂ   €€€€ﬂﬂ€€€€   €€€€€€€€€€€   €€€€€ﬂﬂﬂ   €€€€€  €€€€€   €€€€€   €€€€€   €€€€€ﬂﬂﬂ"); 
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,249); printf("€€€€€      €€€€  €€€€      €€€€€      €€€€€      €€€€€€€€€€€€   €€€€€€‹€€€€€€   €€€€€ﬂﬂ "); 
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,249); printf("€€€€€‹‹‹   €€€€€€€€€€      €€€€€      €€€€€‹‹‹   €€€€€  €€€€€   €€€€€ﬂ€ﬂ€€€€€   €€€€€‹‹‹"); 
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,243); printf(" ﬂﬂﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂ  ﬂﬂﬂﬂ      ﬂﬂﬂﬂﬂ       ﬂﬂﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂ  ﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂﬂﬂﬂ");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,243); printf(" ‹‹‹‹‹‹‹   ‹‹‹‹  ‹‹‹‹      ‹‹‹‹‹       ‹‹‹‹‹‹‹   ‹‹‹‹‹  ‹‹‹‹‹   ‹‹‹‹‹   ‹‹‹‹‹   ‹‹‹‹‹‹‹‹");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,251); printf(" ﬂﬂﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂ  ﬂﬂﬂﬂ      ﬂﬂﬂﬂﬂ       ﬂﬂﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂ  ﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂ   ﬂﬂﬂﬂﬂﬂﬂﬂ");
	
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,251); printf("  ‹‹‹‹‹     ‹‹    ‹‹        ‹‹‹         ‹‹‹‹‹     ‹‹‹    ‹‹‹     ‹‹‹     ‹‹‹     ‹‹‹‹‹‹ ");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,253); printf("  ﬂﬂﬂﬂﬂ     ﬂﬂ    ﬂﬂ        ﬂﬂﬂ         ﬂﬂﬂﬂﬂ     ﬂﬂﬂ    ﬂﬂﬂ     ﬂﬂﬂ     ﬂﬂﬂ     ﬂﬂﬂﬂﬂﬂ ");
	
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,253); printf("   ‹‹‹       ‹    ‹          ‹           ‹‹‹       ‹      ‹       ‹       ‹       ‹‹‹‹  ");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,245); printf("   ﬂﬂﬂ       ﬂ    ﬂ          ﬂ           ﬂﬂﬂ       ﬂ      ﬂ       ﬂ       ﬂ       ﬂﬂﬂﬂ  ");
	
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,245); printf("    1        2    3          4            5        6      7       8       9        10");
	
	newlineENtab(2, 2);	SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
						SetConsoleTextAttribute(h,241); printf("* "); SetConsoleTextAttribute(h,245); printf("* "); SetConsoleTextAttribute(h,249); printf("* "); SetConsoleTextAttribute(h,251); printf("* "); SetConsoleTextAttribute(h,253); printf("* ");
	newlineENtab(2, 7);	SetConsoleTextAttribute(h,223); printf("  BY MAVE  "); SetConsoleTextAttribute(h,240);
	
	newlineENtab(4, 5); SetConsoleTextAttribute(h,241); printf("    </> Press any button to proceed </>"); SetConsoleTextAttribute(h,240);
							getch();
    showMainMenu();
    return 0;
}

void showMainMenu() {
    int choice;
    int y = 1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    for(;;){
	    system("cls");
	    newlineENtab(2, 3);	SetConsoleTextAttribute(h,245);	printf(" ‹‹‹‹‹‹   ‹‹‹‹‹   ‹‹‹‹‹‹‹   ‹‹‹‹‹‹  ‹‹‹‹   ‹‹‹‹     ‹‹‹‹   ‹‹‹‹  ‹‹‹‹‹‹‹");
		newlineENtab(1, 3);	SetConsoleTextAttribute(h,245);	printf("€€€€     €€€ﬂ€€€    €€€    €€€€     €€€€‹‹‹€€€€     €€€€‹ ‹€€€€  €€€€‹   ");
		newlineENtab(1, 3);	SetConsoleTextAttribute(h,245);	printf("€€€€     €€€‹€€€    €€€    €€€€     €€€€ﬂﬂﬂ€€€€     €€€€ ﬂ €€€€  €€€€    ");
		newlineENtab(1, 3);	SetConsoleTextAttribute(h,245);	printf(" ﬂﬂﬂﬂﬂﬂ  ﬂﬂﬂ ﬂﬂﬂ    ﬂﬂﬂ     ﬂﬂﬂﬂﬂﬂ  ﬂﬂﬂﬂ   ﬂﬂﬂﬂ     ﬂﬂﬂﬂ   ﬂﬂﬂﬂ  ﬂﬂﬂﬂﬂﬂﬂ");
		
		newlineENtab(3, 7);		selectOPTION(1,y); printf("Start Game"); //system("COLOR F4");
		newlineENtab(3, 6);		selectOPTION(2,y); printf("       Add Question"); 
		newlineENtab(3, 6);		selectOPTION(3,y); printf("       Leaderboards"); //system("COLOR F0"); 
	    newlineENtab(3, 6);		selectOPTION(4,y); printf("  Rules and Instructions");
	    newlineENtab(3, 6);		selectOPTION(5,y); printf("    About the Creators");
	    newlineENtab(3, 7);		selectOPTION(6,y); printf("Exit  Game");
	    newlineENtab(4, 5);		SetConsoleTextAttribute(h,240); printf("   Use "); SetConsoleTextAttribute(h,253); printf("[W] "); SetConsoleTextAttribute(h,240); printf("& "); SetConsoleTextAttribute(h,253);printf("[S] "); SetConsoleTextAttribute(h,240); printf("buttons to navigate");  
	    fflush(stdin);
	    int pressbutton = getch();
	
		if (pressbutton == 's' || pressbutton == 80){	// down button or down arrow
		    y = (y == 6) ? 1 : y + 1;	// teleport from last button to the first
		} else if (pressbutton == 'w' || pressbutton == 72){	// up button or up arrow
		    y = (y == 1) ? 6 : y - 1;	// teleport from first button to the last
		}
		
		if (pressbutton == 13){	// Return Carriage Button or Enter Button
		    break;	// terminates for loop;
		}
	}
	if(y==1){
		startGame();	
	}else if(y==2){
		showAddQuestions();
	}else if(y==3){
		showLeaderboards();	 
	}else if(y==4){
		showInstructions();		
	}else if(y==5){
		showAbout();
	}else if(y==6){
		con();
	}
}

void startGame(){
	char key;
    int randomquestion[11], queschecker[100] = {0}, quesdisplay;
	int c, n, i, j, r, z, d, t, k, questionsnum, falling;
    int x, y, lastx, lasty, a, b; //basket and border
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	srand(time(NULL));
	
	fp = fopen("randomnumbers.txt", "r"); 
    if (fp == NULL) {
        printf("Error opening file.\n");
        getch();
        showMainMenu();
    }
 	
    flp = fopen("questionsANDanswers.txt", "r"); 
    if (flp == NULL) {
        printf("Error opening file.\n");
        getch();
        showMainMenu();
    }
	
	c=0;
	for(i=0; !feof(fp); i++){
    	for(j=0;j<10;j++){
    		fscanf(fp, "%d ", &list[i].num[j]);	
		}
		fscanf(flp, "%s %d", &list[i].q,&list[i].ans);
    	c++;
	}
	
	fclose(flp);
	fclose(fp);
	
	system("cls");
    fflush(stdin);
    newlineENtab(10, 5); SetConsoleTextAttribute(h,249); printf("ENTER YOUR NICKNAME: ");
    					 SetConsoleTextAttribute(h,240); gets(names);
    score=0;					 
    quesdisplay=0;
    int lives = 3;
    questionsnum=c;
    //falling=0;
    	for(i=0; i<questionsnum; i++){
	        n = rand() % c;
	        while (queschecker[n] != 0) {
	            n = rand() % c;
	        }
	        queschecker[n] = 1;
	        randomquestion[i] = n;
	    }
	do {
		system("cls"); 
		newlineENtab(2, 7);		SetConsoleTextAttribute(h,245); printf("CATCH ME");
	    newlineENtab(2, 2);		SetConsoleTextAttribute(h,240); printf("    Player: %s",names);
	    //newlineENtab(0, 6);		printf("    Level: %d",level);
	    newlineENtab(1, 2);		printf("    Lives: %d",lives);
	    newlineENtab(0, 7);		printf("    Score: %d",score);
		falling=0;
        
		//n=(rand()% 3);
        newlineENtab(1, 2); printf("    Question/s: %s = ?", list[randomquestion[quesdisplay]].q);
	   
	    // GAME
		getPosition(); 
		x = 56; y = 27; // position of basket
		lastx = x; lasty = y;
		r=0;
	  	
		while(1) {  
	    	for (b = 19; b < 100; b++) { // border
				gotoxy(b,7);
				SetConsoleTextAttribute(h,245);	printf("‹");
				gotoxy(b,28);
				SetConsoleTextAttribute(h,245);	printf("‹");
			}
			
			for (b = 7; b < 28; b++) { // border
				gotoxy(30,b);
				SetConsoleTextAttribute(h,245);	printf("‹");
				gotoxy(86,b);
				SetConsoleTextAttribute(h,245);	printf("‹");
			}
			SetConsoleTextAttribute(h,240);
			//r=0;
			// Move the falling objects down
				for (z = 0; z < falling; z++) {
					// basket  
					gotoxy(lastx, lasty);
					printf("     ");
					gotoxy(x, y);
					printf("[___]");
					
					gotoxy(pos[z][0], pos[z][1]);
					printf("   ");
			        if (pos[z][1] < 27)
				        pos[z][1]++;
				    // Check if the object is beyond the left or right border
//				    if (pos[z][0] < 31 || pos[z][0] > 84) {
//				        pos[z][0] = (rand() % (54)) + 31; // given a new random position
//				    }
			        gotoxy(pos[z][0], pos[z][1]);
					if (z == 4 ){
			    		printf("%d",list[randomquestion[quesdisplay]].ans);
			    		d=pos[z][0];
			    		t=pos[z][1];
					}
					else {
			    		printf("%d", list[randomquestion[quesdisplay]].num[z]);
					}
					// Check if the basket caught an object

					 if (t == y && d >= x && d <= x + 4) {
			            score++;
			            SLEEP_TIME-=50000;
			            r=1;
			            t=x;
			            t=8;
			            break;
					}
					else if (t == y && (d < x || d > x + 4)){
			        	r=1;
			        	lives--;
			        	t=x;
			            t=8;
			        	//falling=0;
			        	break;
					}
					
			       
					
					for(k=0;k<falling;k++){
						if(k!=4 && (x==pos[k][0] || x+1==pos[k][0] || x+2==pos[k][0] || x+3==pos[k][0] || x+4==pos[k][0]) && y==pos[k][1]){
							lives--;
							r=2;
							break;
						} 
					}
			        // Check if the object hit the ground
			        if (r==0){
			        	if (pos[z][1] > 26 && pos[z][0]!=d) {
							gotoxy(pos[z][0], pos[z][1]);
							printf("  ");
				            pos[z][1] = 8; // reset/goes back to initial position (back on top)
				            pos[z][0] = (rand() % (54)) + 31; // given a new random position
				        }
					}
					
					
					// Check for user input
					if (_kbhit()) {
						key = _getch();
						if (key == 75 || key == 'a') { // basket moves to the left
						    if (x > 31) {
						        lastx = x;
						        x -= 5;
						    }
						}
						else if (key == 77 || key == 'd') {
						    if (x < 81) {
						        lastx = x;
						        x += 5;
						    }
						}
					}
					
					if(r==2){
						if (pos[z][1] > 26 && pos[z][0]!=d) {
							gotoxy(pos[z][0], pos[z][1]);
							printf("  ");
//				            pos[z][1] = 8; // reset/goes back to initial position (back on top)
//				            pos[z][0] = (rand() % (54)) + 31; // given a new random position
				        }
						break;
					}
				}
		        
			
			if(falling<10){
	        	falling++;
			}    
			if(r==1 || r==2){
				//falling=1;
				//r=0;
//				printf("ssdasd");
//				getch();
				break;
			}
	        usleep(SLEEP_TIME); // sleep between frames
		}
		if(quesdisplay<c)
			quesdisplay++;
	//	questionsnum+=2;
	}while (lives > 0);
    if (lives == 0) {
		gameOver();
	}
    press();
	showMainMenu();
}

getPosition(){
	int x, i, y, randomx[11] = {33, 38, 43, 48, 53, 58, 63, 68, 73, 78, 83}, checker[11] = {0};
	
	srand(time(NULL));
	
	for (i = 0; i < 10; i++) {
		do {
			x = rand() % 11;
		}
		while (checker[x]);
		checker[x] = 1;
//		do {
//			y=(rand() % 1) + 8;
//		}
//		while (y < 8 || y > 27);
			
		pos[i][0] = randomx[x];
		pos[i][1] = 8;
	}
}

gotoxy(int eex, int eey){
	COORD h;
	h.X = eex;
	h.Y = eey;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), h);
}

void gameOver() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("cls");
	newlineENtab(6, 2);	SetConsoleTextAttribute(h,253);	printf(" ‹‹‹‹‹‹‹‹   ‹‹‹‹‹‹‹   ‹‹‹‹   ‹‹‹‹  ‹‹‹‹‹‹‹      ‹‹‹‹‹‹‹‹   ‹‹‹   ‹‹‹  ‹‹‹‹‹‹‹  ‹‹‹‹‹‹‹‹");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("€€€€       €€€€ﬂ€€€€  €€€€‹ ‹€€€€  €€€€        €€€€  €€€€  €€€   €€€  €€€€     €€€€  €€");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("€€€€  ‹‹‹  €€€€ €€€€  €€€€ € €€€€  €€€€ﬂ       €€€€  €€€€  €€€   €€€  €€€€ﬂ    €€€€€€€‹ ");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("€€€€   €€  €€€€‹€€€€  €€€€ ﬂ €€€€  €€€€        €€€€  €€€€   €€€ €€€   €€€€     €€€€ €€€ ");
	newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf(" ﬂﬂﬂﬂﬂﬂﬂﬂ  ﬂﬂﬂﬂ ﬂﬂﬂﬂ  ﬂﬂﬂﬂ   ﬂﬂﬂﬂ  ﬂﬂﬂﬂﬂﬂﬂ      ﬂﬂﬂﬂﬂﬂﬂﬂ     ﬂﬂﬂﬂﬂ    ﬂﬂﬂﬂﬂﬂﬂ  ﬂﬂﬂﬂ ﬂﬂﬂ");
	newlineENtab(5, 6); SetConsoleTextAttribute(h, 240); printf("           Player: "); SetConsoleTextAttribute(h, 249); printf("%s", names);
	newlineENtab(3, 6); SetConsoleTextAttribute(h, 240); printf("      Final Score: "); SetConsoleTextAttribute(h, 249); printf("%d", score);	
	//newlineENtab(3, 5); SetConsoleTextAttribute(h, 240); printf("      		 Level: "); SetConsoleTextAttribute(h, 249); printf("%d", level);
	SetConsoleTextAttribute(h, 240); newlineENtab(4, 0);
	flp = fopen("LDBnamescore.txt", "a"); 
    if (flp == NULL) {
        printf("Error opening file.\n");
        getch();
        showMainMenu();
    }
    fprintf(flp, "\n%s %d", names, score);
    fclose(flp);
	press();
	showMainMenu();
}

void showAddQuestions() {
	struct entry {
		char usernamee[100], passwordd[100];
	}; struct entry list[100];
    char addQUES[100], h[100], username[100], password[100];
    int count=0, c=1, answer, numbers[10], i;

    system("cls");
    if ((fp=fopen("accounts.txt","r")) == NULL) {
        fprintf(stderr,"Error opening file.\n");
        getch();
        showMainMenu();
    }
    fflush(stdin);
    newlineENtab(10, 5);    printf("Username: ");
                            gets(username);
    newlineENtab(3, 5);     printf("Password: ");
                            gets(password);
	c=0;                        
    for(i=0; !feof(fp); i++){
    	fscanf(fp, "%s %s", &list[i].usernamee, &list[i].passwordd);
    	c++;
	}
	for(i=0; i<c; i++){
		if (strcmp(username, list[i].usernamee)==0 && strcmp(password, list[i].passwordd)==0){
			count=1;
			system("cls");
                fflush(stdin);
                newlineENtab(10, 5);    printf("Add a question: ");
                                            gets(addQUES);
                newlineENtab(3, 5);     printf("Answer: ");
                                            //gets(answer);
                                            scanf("%d", &answer);
                if ((ques=fopen("questionsANDanswers.txt","a")) == NULL) {
                    fprintf(stderr,"Error opening file.\n");
                    getch();
        			showMainMenu();
                }
                fprintf(ques, "\n%s %d", addQUES, answer);
                fclose(ques);
                break;
		}if (strcmp(username, list[i].usernamee)==0 && strcmp(password, list[i].passwordd)==1){
			count=2;
		}if (strcmp(username, list[i].usernamee)==1 && strcmp(password, list[i].passwordd)==0){
			count=3;
		}if (strcmp(username, list[i].usernamee)==1 && strcmp(password, list[i].passwordd)==1){
			count=4;
		}  
	}
	if (count==2){
		newlineENtab(2, 5); printf("Wrong password");
		getch();
	    showMainMenu();
    }if (count==3){
		newlineENtab(2, 5); printf("Wrong username");
    	getch();
	    showMainMenu();
	}if (count==4){
		newlineENtab(2, 5); printf("Username doesn't exist");
		getch();
	    showMainMenu();
    }
    //GENERATE 10 RANDOM NUMBERS SA TXT FILE
    if (count==1){
    	if ((flp=fopen("randomnumbers.txt","a")) == NULL) {
	        fprintf(stderr,"Error opening file.\n");
	        getch();
	        showMainMenu();
	    }
	    for(i=0;i<10;i++){
	    	if(i==0)
	    		fprintf(flp, "\n");
	    	do{
	    		numbers[i]= (rand() % answer)+10;
			}while(numbers[i]==answer);   	
	    	fprintf(flp, "%d ", numbers[i]);
		}
	    fclose(flp);
	}
    fclose(fp);
    press();
    showMainMenu();
}

void showLeaderboards(){
    // Code to display leaderboards goes here
    char names[100][100], temp[100];
    int scores[100], i, j, k, tmp;
    system("cls");
    newlineENtab(2, 6);		printf("  CATCH ME");
    newlineENtab(2, 6);		printf(" LEADERBOARDS\n");
    
    if( (fp=fopen("LDBnamescore.txt","r")) == NULL){
		fprintf(stderr,"Error opening file.\n");
		getch();
        showMainMenu();
	}
	k=0;
	for(i=0; !feof(fp); i++){
		fscanf(fp,"%s %d", &names[i], &scores[i]);
		//sort[i]=scores[i];
		k++;
	}
	for (i = 0; i < k; i++){
		for (j = 0; j < k; j++){
			if (scores[j] < scores[i]){
				tmp = scores[i];       // for final grade  
				scores[i] = scores[j];            
				scores[j] = tmp;
				strcpy(temp, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp);       
			}
		}
	}
	for(i=0; i<k; i++){
		newlineENtab(2, 4);		printf("%s",names[i]);
		newlineENtab(0, 5);		printf("%d",scores[i]);
	}
	
    fclose(fp);
    newlineENtab(2, 0);	
    press();
	showMainMenu();
}

void showInstructions(){	// Code to display instructions goes here
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
    system("CLS");
	newlineENtab(2, 7);		SetConsoleTextAttribute(h,223);printf(" CATCH ME ");
    newlineENtab(2, 6);		SetConsoleTextAttribute(h,240);printf("    GAME  INSTRUCTIONS");
    newlineENtab(3, 3);		printf("1. Player will only be given ");SetConsoleTextAttribute(h,253); printf("3 lives");  SetConsoleTextAttribute(h,240); printf(" at the start of the game. Questions");
    newlineENtab(2, 3);		printf("   will be based on mathematical operations.");
	newlineENtab(3, 3);		printf("2. 10 random numbers will be displayed on screen; the player must choose");
	newlineENtab(2, 3);		printf("   the right answer and catch it by moving the basket.");
	newlineENtab(2, 3);		printf("   a. To move the basket, use:\n"); 
	newlineENtab(1, 4);		SetConsoleTextAttribute(h,253); printf("   Left arrow"); SetConsoleTextAttribute(h,240); printf(" for moving to the left & "); SetConsoleTextAttribute(h,253);printf("Right arrow"); SetConsoleTextAttribute(h,240);printf(" for moving to the right");
	newlineENtab(3, 3);		printf("3. If the player caught the wrong answer or missed the correct answer, the");
	newlineENtab(2, 3);		printf("   lives will decrease by 1. The game's over once they used up all 3 lives.");
	press();
	showMainMenu();
}

void showAbout(){	// Code to display about information goes here
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    
	system("cls");
    newlineENtab(2, 7);		SetConsoleTextAttribute(h,223); printf(" CATCH ME ");
    newlineENtab(2, 6);		SetConsoleTextAttribute(h,240); printf("    ABOUT THE CREATORS");
    newlineENtab(5, 4);		SetConsoleTextAttribute(h,253); printf("VERA  AGUILA\t\t\t\t   CHRISTINA TALE");
    newlineENtab(2, 4);		SetConsoleTextAttribute(h,240); printf(" 2022046541\t\t\t\t     2020035391");
    newlineENtab(2, 3);		printf("   BS Applied Mathematics\t\t       BS Applied Mathematics");
    newlineENtab(1, 3);		printf("Information Technology Track\t\t    Information Technology Track");
    newlineENtab(6, 2);		printf("    Project Name: Catch Me\t\t\t Group Name: MAVE");
    newlineENtab(2, 2);		printf("    Submitted to: Mr. Edward Andaya\t\t Date Created: March 2023 - May 2023");
    press();
	showMainMenu();
}

// TECHNICALS
int newlineENtab(int x, int y){	
	int newline,tab;
		for (newline=0;newline<=x-1;newline++)
				printf("\n");
		for (tab=0;tab<=y-1;tab++)
				printf("\t");
}

void press(){
	newlineENtab(4, 6);		printf("Press any key to continue..");
							getch();
}

void con(){
	char cont;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	newlineENtab(4, 5);		printf("   Are you sure you want to exit?");
	newlineENtab(2, 5);		printf("   [Y] Yes");
	newlineENtab(0, 2);		printf("   [N] No");
	newlineENtab(1, 7);		cont=getche();
  	
	switch(toupper(cont)){
  		case 'Y':
  			
			system("cls");
			newlineENtab(6, 2);	SetConsoleTextAttribute(h,253);	printf("‹‹‹‹‹‹‹‹ ‹‹‹  ‹‹‹   ‹‹‹‹‹‹   ‹‹‹‹‹‹    ‹‹‹  ‹‹‹  ‹‹‹    ‹‹‹     ‹‹‹ ‹‹‹‹‹‹‹‹  ‹‹‹  ‹‹‹");
			newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("  €€€€   €€€‹‹€€€  €€€€€€€€  €€€ €€€   €€€  €€€ €€€      €€€   €€€  €€€ﬂﬂ€€€  €€€  €€€");
			newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("  €€€€   €€€€€€€€  €€€  €€€  €€€  €€€  €€€  €€€€€€        €€€‹€€€   €€€  €€€  €€€  €€€");
			newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("  €€€€   €€€ﬂﬂ€€€  €€€€€€€€  €€€   €€€ €€€  €€€ €€€         €€€     €€€‹‹€€€  €€€‹‹€€€");
			newlineENtab(1, 2);	SetConsoleTextAttribute(h,253);	printf("  ﬂﬂﬂﬂ   ﬂﬂﬂ  ﬂﬂﬂ  ﬂﬂﬂ  ﬂﬂﬂ  ﬂﬂﬂ    ﬂﬂﬂﬂﬂﬂ  ﬂﬂﬂ  ﬂﬂﬂ        ﬂﬂﬂ     ﬂﬂﬂﬂﬂﬂﬂﬂ  ﬂﬂﬂﬂﬂﬂﬂﬂ");
  									exit(0);
  		case 'N':			
  			showMainMenu();
  		default:
  			system("cls");
  			newlineENtab(2, 2);		printf("Wrong key. Try again.");
  									con();
   	}
}

int selectOPTION(int x, int y){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(x==y){
		SetConsoleTextAttribute(h,249); 
	}else{
		SetConsoleTextAttribute(h,240); 
	}
}





