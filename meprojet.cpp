//----------------Aymane Talibi---------3IIR2----
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//-----------------------------------------------
using namespace std;//---------------------------
//-----------------------------------------------
    class mint
    {
    private:
        char* maChaine;
    public:
        mint(){
        	maChaine=NULL;
		}
		//------------ Aymane Talibi--3IIR2-----
        mint(char* val){
			while(val[i]){
				if(val[i]>=48&&val[i]<=57){
					maChaine = new char[strlen(val) + 1];
					strcpy(maChaine, val);
				}
				else
				{
					cout << "erreur!!!!" << endl;
				}
			}
		}
		//------------ Aymane Talibi--3IIR2-----
        mint(const mint &myMint){
        	this.maChaine=new char[strlen(myMint.maChaine) + 1];
        	strcpy(this.maChaine,myMint.maChaine);
		}
		//------------ Aymane Talibi--3IIR2-----
		mint(const int myInt){
			this.maChaine = new char[strlen(itoa(myInt)) + 1];	
			strcpy(this.maChaine, itoa(myInt));
		}
		//------------ Aymane Talibi--3IIR2-----
        ~mint(){
        	delete this.maChaine;
		}
        //------------ Aymane Talibi--3IIR2-----
        mint operator=(const mint &myMint){
			delete this.maChaine;
			this.maChaine = new char[strlen[myMint] + 1];
			strcpy(this.maChaine,myMint.maChaine);
			return *this;
		}
		//------------ Aymane Talibi--3IIR2-----
        mint operator=(const int myInt){
			delete this.maChaine;
			this.maChaine = new char[strlen(itoa(myInt)) + 1];
			int r=1,q=myInt,i=0;
        	while(r!=0){
            	r=q%10;
            	q=q/10;
            	this.maChaine[i]=r+48;
            	i++;
        	}
			return *this;
		}
        //------------ Aymane Talibi--3IIR2-----
        mint operator+=(const mint &myMint){
        	int i,a,b,j;
        	for(i=0;i<strlen(this.maChaine);i++){
            	for(j=0;j<strlen(myMint.maChaine);j++){
                	a=this.maChaine[i]+48;
                	b=myMint.maChaine[j]+48;
                	int somme=a+b;
                	if(isNull(a)){
                		somme=b;
					}
					else if(isNull(b)){
						somme=a;
					}
                	if(somme>=10){
                    	this.maChaine[j]=(somme%10)-48;
                    	if((this.maChaine[j+1]+=1)<10){
                    		this.maChaine[j+1]+=1;
						}
						else{
							this.maChaine[j+1]+=0;
							this.maChaine[j+2]+=1;
						}
                	}
                	else{
                    	this.maChaine[j]=somme-48;
                	}
            	}
        	}
        	return *this;
		}
        //------------ Aymane Talibi--3IIR2-----
        mint operator+(const mint & myMint1,const mint & myMint2){
        	int i,a,b,somme;
        	mint myMint3;
        	while(myMint1.maChaine[i]||myMint2.maChaine[i]){
        			int a=myMint1.maChaine[i]+48;
        			int b=myMint1.maChaine[i]+48;
        			if(isNull(a)){
        				somme=b;
					}
					else if(isNull(b)){
						somme=a;
					}
					else if(isNull(b)&&isNull(a)){
						somme=0;
					}
					else{
						somme=a+b;
					}
					myMint3.maChaine= new char[strlen(itoa(somme))];
					for(int j=0;j<strlen(myMint3.maChaine);j++){
						if(somme<10){
							myMint3.maChaine[j]=somme;
						}
						else if(somme>10&&myMint3.maChaine[j+1]+1<10){
							myMint3.maChaine[j]=(somme-10);
							myMint3.maChaine[j+1]+=1;
						}
						else{
							myMint3.maChaine[j]=(somme-10);
							myMint3.maChaine[j+1]=0;
							myMint3.maChaine[j+2]+=1;
						}    						
					}
			}
			return myMint3;
		}
        //------------ Aymane Talibi--3IIR2-----
        unsigned int convertToUnsigned(const mint &myMint){
	 		unsigned int ourUnsigned=0;
	 		int fois=1;
	 		for(int count=0;count<strlen(myMint.maChaine);count++){
	 			ourUnsigned+=myMint.maChaine[count]*fois;
	 			fois*=10;
		 	}
		 	return ourUnsigned;
	    }
        //------------ Aymane Talibi--3IIR2-----
        double converFloat(const mint &myMint){
        	double flo=atoi(myMint.maChaine);
        	return flo;
    	}
        //------------ Aymane Talibi--3IIR2-----
        bool operator<(const mint &myMint){
        	if(strlen(this.maChaine)<strlen(myMint.maChaine)){
            	return true;
        	}
        	else if(strlen(this.maChaine)>strlen(myMint.maChaine)){
            	return false;
        	}
        	else{
            	if(this.maChaine<myMint.maChaine){
                	return true;
            	}
            	else{ 
                	return false;
            	}
        	}
		}
		//------------ Aymane Talibi--3IIR2-----
        bool operator>(const mint &myMint){
        	if(strlen(this.maChaine)>strlen(myMint.maChaine)){
            	return true;
        	}
        	else if(strlen(this.maChaine)<strlen(myMint.maChaine)){
            	return false;
        	}
        	else{
            	if(this.maChaine>myMint.maChaine){
                	return true;
            	}
            	else{ 
                	return false;
            	}
        	}
		}
        //------------ Aymane Talibi--3IIR2-----
        bool operator<=(const mint &myMint){
			if(strlen(this.maChaine)<=strlen(myMint.maChaine)){
				return true;
			}
			else{
				return false;
			}	
			
		}
        //------------ Aymane Talibi--3IIR2-----
        bool operator>=(const mint &myMint){
        	if(strlen(this.maChaine)>=strlen(myMint.maChaine)){
				return true;
			}
			else{
				return false;
			}
		}
    };// fin de la classe mint
//------------ Aymane Talibi--3IIR2-----

int main(){
	
	return 0;
}
