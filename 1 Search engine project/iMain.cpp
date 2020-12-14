# include "iGraphics.h"
# include "stdio.h"
# include "string.h"
# include "stdlib.h"
/* 
	function iDraw() is called again and again by the system.
*/

int flag=0,count=0,i,j,k,l,press=0,cx=625,cy=35,dx=6,dy=6,pos,istop,isleft,isright,lifecount=1;

int arr[250][3];

void iDraw()
{
	iClear();
	istop=0;
	iShowBMP(100,0,"starting image.bmp");
	if(flag==0){
		iSetcolor(0,1,0);
		for(i=595;i<=700;i+=21){
			for(j=0;j<=1200;j+=51){
				iFilledRectangle(j,i,50,20);
				arr[count][0]=j;
				arr[count][1]=i;
				arr[count][2]=0;
				count++;
				//printf("%d %d %d\n",arr[count-1][0],arr[count-1][1],arr[count-1][2]);
			}
		}
		iSetcolor(1,1,0);
		iFilledRectangle(575,10,100,15);
		iSetcolor(1,0,0);
		iFilledCircle(625,35,10,100);
		if(press==1) flag=5;
		else if(press==2) flag=2;
		else flag=0;
		cx=625;
		cy=35;
		dx=6;dy=6;
	}

	else {

		//istop=0;
		//isleft=0;
		//isright=0;
		
		//iSetcolor(1,1,0);
		//iFilledRectangle(pos,10,100,15);


		iSetcolor(0,1,0);
		for(l=0;l<count;l++){
			if(arr[l][2]==0){
				iFilledRectangle(arr[l][0],arr[l][1],50,20);
			}
		}
		
		if(cy>=595){
			printf("YAAAAAAAAA ");
			for(k=0;k<count;k++){
				if(cx>=arr[k][0] && cx<=arr[k][0]+50 && cy>=arr[k][1] && cy<=arr[k][1]+20 && arr[k][2]==0){
					arr[k][2]=1;
					istop=1;
					break;
				}
			}
			printf(" %d %d\n",istop,isright);
			printf("%d %d\n",arr[k][0],arr[k][1]);
		}

		iSetcolor(0,1,0);
		for(l=0;l<count;l++){
			if(arr[l][2]==0){
				iFilledRectangle(arr[l][0],arr[l][1],50,20);
			}
		}

		if(flag==-1){
			iSetcolor(1,1,0);
			iFilledRectangle(pos,10,100,15);
			iSetcolor(1,0,0);
			iFilledCircle(625,35,10,100);
			if(press==1) flag=5;
			else if(press==2) flag=2;
			cx=625;
			cy=35;
			dx=6;
			dy=6;
		}

		else if(flag==2){
			iSetcolor(1,1,0);
			iFilledRectangle(pos,10,100,15);
			if(istop==0 && cx+10>1224) flag=5;
			else if(istop==1 && cx+10>=1224) flag=4;
			else if(istop==1 || cy+10>=700) flag=3;
			//else if(isright==1) flag=5;
			//else if(istop==1 && isright==1) flag=4;
			else if(cy+10>=700) flag=3;
			else{
				iSetcolor(1,0,0);
				iFilledCircle(cx+=dx,cy+=dy,10,200);
				flag=2;
			}
		}

		else if(flag==5){
			iSetcolor(1,1,0);
		iFilledRectangle(pos,10,100,15);
			if(istop==0 && cx-10<0) flag=2;
			else if(istop==1 && cx-10<0) flag=3;
			else if(istop==1 || cy+10>=700) flag=4;
			//else if(isleft==1) flag=2;
			else{
				iSetcolor(1,0,0);
				iFilledCircle(cx-=dx,cy+=dy,10,200);
				flag=5;
			}
		}

		else if(flag==3){
			iSetcolor(1,1,0);
		iFilledRectangle(pos,10,100,15);
			if(cx+10<=1224 && cy-10>=35){
				iSetcolor(1,0,0);
				iFilledCircle(cx+=dx,cy-=dy,10,100);
				flag=3;
			}
			else if(cx+10>1224) flag=4;
			else if(cx+10>=pos+50 && cx+10<=pos+100){
				flag=2;
				if(cx-pos-50==0){
					dx=0;
					dy=6;
				}
				else if(cx-pos-50<=10){
					dx=2;
					dy=6;
				}
				else if(cx-pos-50<=40){
					dx=6;
					dy=6;
				}
				else{
					dx=6;
					dy=3;
				}
			}
			else if(cx+10>=pos && cx+10<pos+50){
				flag=5;
				if(cx+10-pos<=10){
					dx=6;
					dy=2;
				}
				else if(cx+10-pos==50){
					dx=0;
					dy=6;
				}
				else if(cx+10-pos>=40){
					dx=3;
					dy=6;
				}
				else{
					dx=6;
					dy=6;
				}
			}
			//else if(istop==1) flag=5;
			else{
				if(lifecount++<=3){
					flag=-1;
					press=0;
					pos=575;
				}
				else{
					flag=0;
					press=0;
				}
			}
		}

		else if(flag==4){
			iSetcolor(1,1,0);
		iFilledRectangle(pos,10,100,15);
			if(cx-10>=0 && cy-10>=35){
				iSetcolor(1,0,0);
				iFilledCircle(cx-=dx,cy-=dy,10,100);
				flag=4;
			}

			else if(cx-10<0) flag=3;
			else if(cx-10>pos && cx-10<=pos+50){
				flag=5;
				if(cx-10-pos<=10){
					dx=6;
					dy=2;
				}
				else if(cx-10-pos==50){
					dx=0;
					dy=6;
				}
				else if(cx-10-pos>=40){
					dx=3;
					dy=6;
				}
				else{
					dx=6;
					dy=6;
				}
			}
			else if(cx-10>pos+50 && cx-10<pos+100){
				flag=2;
				if(cx-10-pos-50==0){
					dx=0;
					dy=6;
				}
				else if(cx-10-pos-50<=10){
					dx=2;
					dy=6;
				}
				else if(cx-10-pos-50>=40){
					dx=6;
					dy=3;
				}
				else{
					dx=6;
					dy=6;
				}
			}
			//else if(istop==1) flag=2;
			else{
				if(lifecount++<=3){
					flag=-1;
					press=0;
					pos=575;
				}
				else{
					flag=0;
					press=0;
				}
			}
		}
	}
	//place your drawing codes here	
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	if(mx+100>1224) pos=1124;
	else if(mx<0) pos=0;
	else pos=mx;
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(flag==0 || flag==-1){
			if(mx>625) press=1;
			else press=2;
		}
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 
	iInitialize(1224,700, "<<<DX BALL GAME>>>");
	return 0;
}	