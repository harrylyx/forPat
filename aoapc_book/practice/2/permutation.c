#include <stdio.h>

int main(){
    for(int a=1;a<=4;a++){
		for(int b=1;b<=9;b++){
			if(b==a)
				continue;
			//printf("b%d\n",b);
			for(int c=1;c<=9;c++){
				if(c==a||c==b)
					continue;
				//printf("c%d\n",c);
				for(int d=1;d<=9;d++){
					if(d==a||d==b||d==c)
						continue;
					for(int e=1;e<=9;e++){
						if(e==a||e==b||e==c||e==d)
							continue;
						for(int f=1;f<=9;f++){
							if(f==a||f==b||f==c||f==d||f==e)
								continue;
							for(int g=1;g<=9;g++){
								if(g==a||g==b||g==c||g==d||g==e||g==f)
									continue;
								for(int h=1;h<=9;h++){
									if(h==a||h==b||h==c||h==d||h==e||h==f||h==g)
										continue;
									for(int i=1;i<=9;i++){
										if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h)
											continue;
										int one = 100*a+10*b+c;
										int two = 100*d+10*e+f;
										int three = 100*g+10*h+i;
                                        if(one*2 == two && one*3 == three)
											printf("%d %d %d\n", one, two, three);
									}
								}
							}
						}
					}
				}
			}
		}
    }
    return 0;
}
