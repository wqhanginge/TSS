#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<conio.h>
using namespace std;//update:�������*��ʾ�ϲ������

void title(int);void top(int,int,int);int small(int,int);
void bi(int,int,int);void rules(int,int,int);void help(int,int,int);void options(int,int,int);
void rands(int,int,int);void show(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
void select(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
int ask(int,int);int judge(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
void add(int,int,int,int,int,int,int,int,int,int);
void end(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
int main(){
	int l=0,i=3,s=10001;
	srand((unsigned int)time(NULL));
	top(l,i,s);
	return 0;
}
void title(int l){
	if(l==0){cout << "The Strange Sum 5.4" << endl;}else{cout<<"����ĺ� v5.4"<<endl;}
	cout << "===================================================================" << endl;
}
void top(int l,int i,int s){
	int mode;
	title(l);
	if(l==0){cout << "  1.\tstart\n  2.\tbrief introduction\n  3.\trules\n  4.\thelp\n  5.\toptions\n  0.\tquit" << endl;}
	else{cout<<"  1.\t��ʼ��Ϸ\n  2.\t���\n  3.\t����\n  4.\t����\n  5.\t����\n  0.\t�˳�"<<endl;}
	cout << "==================================" << endl;
	do{
		if(l==0){cout << "please make a choice:";}else{cout<<"��ѡ��:";}
		cin >> mode;
	} while (mode != 1 && mode != 2 && mode != 3 && mode != 4 && mode != 5 && mode != 0);
	system("cls");
	if (mode == 1){ rands(l,i,s); }
	if (mode == 2){ bi(l,i,s); }
	if (mode == 3){ rules(l,i,s); }
	if (mode == 4){ help(l,i,s); }
	if (mode == 5){ options(l,i,s); }
}
int small(int l,int a){
	int s;
	if(a==1){
		if(l==0){cout<<"\tthe sum is too small!\nplease set again:";}
		else{cout<<"\t�����̫С��!\n�������趨:";}
		cin>>s;
		return s;
	}
	else{
		if(l==0){
			cout<<"\n====================================="<<endl;
			cout<<"= ATTENTION!The sum you've set is   ="<<endl;
			cout<<"= too small for this size of chart! ="<<endl;
			cout<<"= Press any key to reset.           ="<<endl;
			cout<<"====================================="<<endl;
		}
		else{
			cout<<"\n============================="<<endl;
			cout<<"= ע��!������һ�ߴ�ı���� ="<<endl;
			cout<<"= ˵,��ո��趨�ĺ�̫С��!  ="<<endl;
			cout<<"= �밴���������.           ="<<endl;
			cout<<"============================="<<endl;
		}
		_getch();
		return 0;
	}
}
void options(int l,int i,int s){
	char mode;
op:
	title(l);
	if(l==0){cout<<"the sum:\n\t1.random";}else{cout<<"��:\n\t1.�������";}
	if(s>10000){cout<<"��"<<endl;}else{cout<<endl;}
	if(l==0){cout<<"\t2.custom";}else{cout<<"\t2.�Զ���";}
	if(s>10000){cout<<endl;}else{cout<<"�� "<<s<<endl;}
	cout<<"=================================="<<endl;
	if(l==0){cout<<"size of chart:";}else{cout<<"���ߴ�:";}
	cout<<"\n\t3.3x3";if(i==3){cout<<"��";}else{cout<<"  ";}
	cout<<"\t7.7x7";if(i==7){cout<<"��"<<endl;}else{cout<<endl;}
	cout<<"\t4.4x4";if(i==4){cout<<"��";}else{cout<<"  ";}
	cout<<"\t8.8x8";if(i==8){cout<<"��"<<endl;}else{cout<<endl;}
	cout<<"\t5.5x5";if(i==5){cout<<"��";}else{cout<<"  ";}
	cout<<"\t9.9x9";if(i==9){cout<<"��"<<endl;}else{cout<<endl;}
	cout<<"\t6.6x6";if(i==6){cout<<"��"<<endl;}else{cout<<endl;}
	cout<<"=================================="<<endl;
	if(l==0){cout<<"language:\n\tE.English��"<<endl;}else{cout<<"����:\n\tE.Emglish"<<endl;}
	cout<<"\tC.����";if(l==0){cout<<endl;}else{cout<<"��"<<endl;}
	cout<<"=================================="<<endl;
	if(l==0){cout<<"\t0.back"<<endl;}else{cout<<"\t0.����"<<endl;}
	cout<<"=================================="<<endl;
	do{
		if(l==0){cout<<"please make a chioce:";}else{cout<<"��ѡ��:";}
		cin>>mode;
	}while(mode!='0'&&mode!='1'&&mode!='2'&&mode!='3'&&mode!='4'&&mode!='5'&&mode!='6'&&mode!='7'&&mode!='8'&&mode!='9'&&mode!='e'&&mode!='c'&&mode!='E'&&mode!='C');
	if(mode=='1'){
		s=10001;
		if(l==0){cout<<"\tdone"<<endl;}
		else{cout<<"\t���"<<endl;}
	}
	if(mode=='2'){
		if(l==0){cout<<"please set a sum:";}else{cout<<"���趨һ����:";}
		cin>>s;
		do{
			while(s>10000){
				if(l==0){cout<<"\tthe sum is too large!\nplease set again:";}
				else{cout<<"\t�����̫����!\n�������趨:";}
				cin>>s;
			}
			while(i==3&&s<5){s=small(l,1);}
			while(i==4&&s<10){s=small(l,1);}
			while(i==5&&s<20){s=small(l,1);}
			while(i==6&&s<30){s=small(l,1);}
			while(i==7&&s<45){s=small(l,1);}
			while(i==8&&s<60){s=small(l,1);}
			while(i==9&&s<75){s=small(l,1);}
		}while(s>10000);
		if(l==0){cout<<"\tdone"<<endl;}else{cout<<"\t���"<<endl;}
	}
	if(mode=='3'||mode=='4'||mode=='5'||mode=='6'||mode=='7'||mode=='8'||mode=='9'){
		if(mode=='3'&&s<5){small(l,2);}
		else if(mode=='4'&&s<10){small(l,2);}
		else if(mode=='5'&&s<20){small(l,2);}
		else if(mode=='6'&&s<30){small(l,2);}
		else if(mode=='7'&&s<45){small(l,2);}
		else if(mode=='8'&&s<60){small(l,2);}
		else if(mode=='9'&&s<75){small(l,2);}
		else{
			i=mode-'0';
			if(l==0){cout<<"\tdone"<<endl;}
			else{cout<<"\t���"<<endl;}
		}
	}
	if(mode=='e'||mode=='E'){l=0;}
	if(mode=='c'||mode=='C'){l=1;}
	system("cls");
	if(mode!='0'){goto op;}
	else{top(l,i,s);}
}
void bi(int l,int i,int s){
	title(l);
	if(l==0){
		cout << "Brief Introduction:" << endl;
		cout << "===================================================================" << endl;
		cout << "This is a game from an old time." << endl<<endl;
		cout << "People can choose some numbers from a chart with several numbers," << endl;
		cout << "but they must follow the rules.Then they should add all the numbers" << endl;
		cout << "up.Even if they choose different numbers in one chart,the sum is" << endl;
		cout << "always the same.What a strange thing!" << endl<<endl;
		cout << "At that time it was used for a gamble,so that the hoster will"<<endl;
		cout << "always be the winner."<<endl<<endl;
		cout << "Although it sounds magic,the secret of it is very simple.You can" << endl;
		cout << "try your best to find it out."<<endl;
		cout << "===================================================================" << endl;
		cout << "press any key to continue";
	}
	else{
		cout << "���:" <<endl;
		cout << "============================================================="<<endl;
		cout << "����һ������ʱ��ʹ��ڵ���Ϸ��"<<endl<<endl;
		cout << "����ѭ�����ǰ���£����ǿ��Դ�һ��д�����ֵı����ѡ������"<<endl;
		cout << "���֣�Ȼ����⼸�����ּ�����������������ǣ���ʹ����ѡ����"<<endl;
		cout << "��ͬ�����֣��ֱ�������ĺͶ���һ����!"<<endl<<endl;
		cout << "����Щ����������Ϸ�������ڶĲ��ϣ�ͨ��������֤ׯ��ÿ�ζ�"<<endl;
		cout << "��Ӯ�öĲ���"<<endl<<endl;
		cout << "��Ȼ��������ʮ�����棬��������ԭ��ȴʮ�ּ򵥡�������Լ���"<<endl;
		cout << "�취�����ҳ�����"<<endl;
		cout << "============================================================="<<endl;
		cout << "�밴���������";
	}
	_getch(); system("cls"); top(l,i,s);
}
void rules(int l,int i,int s){
	title(l);
	if(l==0){
		cout << "Rules:" << endl;
		cout << "===================================================================" << endl;
		cout << "1st.  Choose one number in the chart." << endl;
		cout << "2nd.  Delete the numbers which are in the same transverse line and" << endl;
		cout << "      vertical line as the last number you've chosen." << endl;
		cout << "3rd.  Choose another number in the chart." << endl;
		cout << "4th.  Repeat step 2 and step 3,until there is no more number to"<<endl;
		cout << "      choose.You can choose anyone number at most once."<<endl;
		cout << "5th.  Add all the chosen numbers up." << endl;
		cout << "6th.  Use a same chart and do step 1 to 5 at least 3 times."<<endl;
		cout << "7th.  The chat must be the same during one game."<<endl;
		cout << "===================================================================" << endl;
		cout << "press any key to continue";
	}
	else{
		cout << "����:"<<endl;
		cout << "============================================================="<<endl;
		cout << "1st.  ����������ѡ��һ������"<<endl;
		cout << "2nd.  ɾ�����������ͬһ���к�ͬһ���е���������"<<endl;
		cout << "3rd.  ��ʣ�µ�������ѡһ����"<<endl;
		cout << "4th.  �ظ�����2��3��ֱ����û������ѡ���κ�һ���������ֻ��"<<endl;
		cout << "      ѡ��һ�Ρ�"<<endl;
		cout << "5th.  ��ѡ�����������ּ�������"<<endl;
		cout << "6th.  ��һ����ͬ�ı���ظ�����1��5����3�Ρ�"<<endl;
		cout << "7th.  ��һ����Ϸ�б���ʹ����ȫ��ͬ�ı��"<<endl;
		cout << "============================================================="<<endl;
		cout << "�밴���������";
	}
	_getch(); system("cls"); top(l,i,s);
}
void help(int l,int i,int s){
	title(l);
	if(l==0){
		cout << "Help:" << endl;
		cout << "===================================================================" << endl;
		cout << "When you start the game,you will get a chart       �����Щ��Щ���" << endl;
		cout << "like this.There are several numbers beside the    3��25��24��26��"<< endl;
		cout << "chart,just like a coordinate.For example,if you    �����੤�੤��"<<endl;
		cout << "input'32'means you choose'67'.The program will    2��66��65��67��" << endl;
		cout << "help you calculate the sum.                        �����੤�੤��" << endl;
		cout << "                                                  1��9 ��8 ��10��" << endl;
		cout << "This program will set a sum for each chart,or you  �����ة��ة���" << endl;
		cout << "can set the sum in options.But the sum must be       1   2   3" << endl;
		cout << "smaller than 10000.Here is a chart about the smallest" << endl;
		cout << "number of each kind of chart." << endl;
		cout << "�������Щ����Щ����Щ����Щ����Щ����Щ�����"<<endl;
		cout << "�� 3x3�� 4x4�� 5x5�� 6x6�� 7x7�� 8x8�� 9x9��"<<endl;
		cout << "�������੤���੤���੤���੤���੤���੤����"<<endl;
		cout << "��   5��  10��  20��  30��  45��  60��  75��"<<endl;
		cout << "�������ة����ة����ة����ة����ة����ة�����"<<endl;
		cout << "Besides,the sum must be integer."<<endl;
		cout << "===================================================================" << endl;
	}
	else{
		cout << "����:"<<endl;
		cout << "============================================================="<<endl;
		cout << "���㿪ʼ��Ϸʱ�����õ�һ���������ı�   �����Щ��Щ���"<<endl;
		cout << "�ڱ���Ա���һЩ���֣�����һ������ϵһ    3��25��24��26��"<<endl;
		cout << "�����������ѡ������'67'��������'32'��     �����੤�੤��"<<endl;
		cout << "�˳����������͡�                      2��66��65��67��" << endl;
		cout << "                                           �����੤�੤��" << endl;
		cout << "�˳����Ϊÿһ�ű���趨һ���ͣ�������    1��9 ��8 ��10��" << endl;
		cout << "Ҳ�������������Լ��趨һ���ͣ��������     �����ة��ة���" << endl;
		cout << "�ͱ���С��10000��������һ�ű��г���ÿһ      1   2   3" << endl;
		cout << "�ֳߴ�ı��������ĺ͵���Сֵ��"<<endl;
		cout << "�������Щ����Щ����Щ����Щ����Щ����Щ�����"<<endl;
		cout << "�� 3x3�� 4x4�� 5x5�� 6x6�� 7x7�� 8x8�� 9x9��"<<endl;
		cout << "�������੤���੤���੤���੤���੤���੤����"<<endl;
		cout << "��   5��  10��  20��  30��  45��  60��  75��"<<endl;
		cout << "�������ة����ة����ة����ة����ة����ة�����"<<endl;
		cout << "����֮�⣬�趨�ĺͱ�����������"<<endl;
		cout << "============================================================="<<endl;
	}
	if(l==0){cout << "press any key to continue";}
	else{cout << "�밴���������";}
	_getch();
	if(l==0){
		cout << "\rThis program will judge if you choose the number which you cannot" << endl;
		cout << "choose or which is non-existent.If you do so,it will show the" << endl;
		cout << "prompt again,until you choose the right number." <<endl<<endl;
		cout << "Every time you reach the end of a turn,the program will show 'try" << endl;
		cout << "again<y/r/q>?','y'means'yes','r'means'return to title','q'means" << endl;
		cout << "'quit'.You can input 0 during a turn to break the game and get to" << endl;
		cout << "this prompt."<<endl<<endl;
		cout << "You'll be given a new chart in new game every time you choose'r'!"<<endl<<endl;
		cout << "ATTENTION!The program may break down if you input the wrong" << endl;
		cout << "character.If so,please press Ctrl+C or Alt+F4 to close it.Besides," << endl;
		cout << "you can also close its window directly by clicking 'X'." <<endl<<endl;
		cout << "I think you make sense of it.\nHave fun!"<<endl;
		cout << "===================================================================" << endl;
		cout << "press any key to continue";
	}
	else{
		cout << "\r�˳�����ж�����ѡ��������ǲ��Ǵ��ڻ��ܲ���ѡ������ǲ���"<<endl;
		cout << "�ڻ���ѡ����������ʾ��ʾ��䣬ֱ����ѡ�˷��Ϲ��������"<<endl<<endl;
		cout << "ÿ�������һ��ѡ��ʱ���˳������ʾ������һ��<y/r/q>?������"<<endl;
		cout << "��'y'��ʾ'��'��'r'��ʾ'�ص���ʼ����'��'q'��ʾ'�˳�'����Ҳ��"<<endl;
		cout << "����ѡ���ֵĹ���������'0'ֱ��������Ϸ�������ѡ�"<<endl<<endl;
		cout << "�����ѡ��'r'�����������Ϸ�еõ�һ���µı��"<<endl<<endl;
		cout << "ע��!!!  ��������벻��Ҫ����ַ�[�Ƿ�����]���˳�����ܻ�"<<endl;
		cout << "����!��������������밴'Ctrl+C'����'Alt+F4'ǿ���˳���Ҳ��"<<endl;
		cout << "����굥�����Ͻǹرհ�ť'X'���رա�"<<endl<<endl;
		cout << "�������������ҵ���˼��\nף����Ŀ���!"<<endl;
		cout << "============================================================="<<endl;
		cout << "�밴���������";
	}
	_getch(); system("cls"); top(l,i,s);
}
void rands(int l,int i,int s){
	int aa,ab,ac,ad,ae,af,ag,ah,ai,ba,bb,bc,bd,be,bf,bg,bh,bi,m,c=0;
	for(int x=1;x<i;x++){c+=x;}
	if(s>10000){
ra:
		for(int v=0;v<i;v++){
			if(i==3){m=rand()%100;}
			else if(i==4){m=rand()%150;}
			else if(i==5){m=rand()%191+10;}
			else if(i==6){m=rand()%201+50;}
			else if(i==7){m=rand()%901+100;}
			else if(i==8){m=rand()%2401+100;}
			else if(i==9){m=rand()%4901+100;}
			if(v==0){aa=m;}else if(v==1){ab=m;}else if(v==2){ac=m;}else if(v==3){ad=m;}else if(v==4){ae=m;}
			else if(v==5){af=m;}else if(v==6){ag=m;}else if(v==7){ah=m;}else if(v==8){ai=m;}
		}
		if(i==3&&aa+ab+ac<5){goto ra;}
		else if(i==4&&aa+ab+ac+ad<10){goto ra;}
		else if(i==5&&aa+ab+ac+ad+ae<20){goto ra;}
		else if(i==6&&aa+ab+ac+ad+ae+af<30){goto ra;}
		else if(i==7&&aa+ab+ac+ad+ae+af+ag<45){goto ra;}
		else if(i==8&&aa+ab+ac+ad+ae+af+ag+ah<60){goto ra;}
		else if(i==9&&aa+ab+ac+ad+ae+af+ag+ah+ai<75){goto ra;}
	}
	else{
		aa=rand()%((s-c)/6*5);
		do{ab=rand()%((s-c)/6*5);}while(ab>=s-c-aa);
		if(i==3){ac=s-c-aa-ab;ai=ah=ag=af=ad=ae=0;goto rb;}else{ac=rand()%(s-c-aa-ab);}
		if(i==4){ad=s-c-aa-ab-ac;ai=ah=ae=af=ag=0;goto rb;}else{ad=rand()%(s-c-aa-ab-ac);}
		if(i==5){ae=s-c-aa-ab-ac-ad;ai=ah=af=ag=0;goto rb;}else{ae=rand()%(s-c-aa-ab-ac-ad);}
		if(i==6){af=s-c-aa-ab-ac-ad-ae;ai=ah=ag=0;goto rb;}else{af=rand()%(s-c-aa-ab-ac-ad-ae);}
		if(i==7){ag=s-c-aa-ab-ac-ad-ae-af;ai=ah=0;goto rb;}else{ag=rand()%(s-c-aa-ab-ac-ad-ae-af);}
		if(i==8){ah=s-c-aa-ab-ac-ad-ae-af-ag;ai=0;goto rb;}else{ah=rand()%(s-c-aa-ab-ac-ad-ae-af-ag);}
		if(i==9){ai=s-c-aa-ab-ac-ad-ae-af-ag-ah;}
	}
rb:
	ba=rand()%i;
	do{bb=rand()%i;}while(bb==ba);
	if(i==3){bc=c-ba-bb;bd=be=bf=bg=bh=bi=0;goto show;}else{do{bc=rand()%i;}while(bc==bb||bc==ba);}
	if(i==4){bd=c-ba-bb-bc;be=bf=bg=bh=bi=0;goto show;}else{do{bd=rand()%i;}while(bd==bc||bd==bb||bd==ba);}
	if(i==5){be=c-ba-bb-bc-bd;bf=bg=bh=bi=0;goto show;}else{do{be=rand()%i;}while(be==ba||be==bb||be==bc||be==bd);}
	if(i==6){bf=c-ba-bb-bc-bd-be;bg=bh=bi=0;goto show;}else{do{bf=rand()%i;}while(bf==ba||bf==bb||bf==bc||bf==bd||bf==be);}
	if(i==7){bg=c-ba-bb-bc-bd-be-bf;bh=bi=0;goto show;}else{do{bg=rand()%i;}while(bg==ba||bg==bb||bg==bc||bg==bd||bg==be||bg==bf);}
	if(i==8){bh=c-ba-bb-bc-bd-be-bf-bg;bi=0;goto show;}
	else{do{bh=rand()%i;}while(bh==ba||bh==bb||bh==bc||bh==bd||bh==be||bh==bf||bh==bg);}
	if(i==9){bi=c-ba-bb-bc-bd-be-bf-bg-bh;}
show:
	show(l,i,s,aa,ab,ac,ad,ae,af,ag,ah,ai,ba,bb,bc,bd,be,bf,bg,bh,bi);
}
void show(int l,int i,int s,int aa, int ab, int ac,int ad,int ae,int af,int ag,int ah,int ai,int ba, int bb, int bc,int bd,int be,int bf,int bg,int bh,int bi){
	int m,n,w=i;
	title(l);
	cout << "  �������Щ����Щ���";
	if(i==3){cout<<"��"<<endl;}
	if(i==4){cout<<"�Щ�����"<<endl;}
	if(i==5){cout<<"�Щ����Щ�����"<<endl;}
	if(i==6){cout<<"�Щ����Щ����Щ�����"<<endl;}
	if(i==7){cout<<"�Щ����Щ����Щ����Щ�����"<<endl;}
	if(i==8){cout<<"�Щ����Щ����Щ����Щ����Щ�����"<<endl;}
	if(i==9){cout<<"�Щ����Щ����Щ����Щ����Щ����Щ�����"<<endl;}
	for(int u=0;u<i;u++){
		if(w==1){m=aa;}if(w==2){m=ab;}if(w==3){m=ac;}if(w==4){m=ad;}if(w==5){m=ae;}
		if(w==6){m=af;}if(w==7){m=ag;}if(w==8){m=ah;}if(w==9){m=ai;}
		cout<<' '<<w<<"��";
		for(int v=0;v<i;v++){
			if(v==0){n=ba;}if(v==1){n=bb;}if(v==2){n=bc;}if(v==3){n=bd;}if(v==4){n=be;}
			if(v==5){n=bf;}if(v==6){n=bg;}if(v==7){n=bh;}if(v==8){n=bi;}
			if(m+n<10){cout<<"  "<<m+n<<" ��";if(v+1==i){cout<<endl;}}
			if(m+n>9&&m+n<100){cout<<' '<<m+n<<" ��";if(v+1==i){cout<<endl;}}
			if(m+n>99&&m+n<1000){cout<<' '<<m+n<<"��";if(v+1==i){cout<<endl;}}
			if(m+n>999){cout<<m+n<<"��";if(v+1==i){cout<<endl;}}
		}
		if(u!=i-1){
			cout << "  �������੤���੤��";
			if(i==3){cout<<"��"<<endl;}
			if(i==4){cout<<"�੤����"<<endl;}
			if(i==5){cout<<"�੤���੤����"<<endl;}
			if(i==6){cout<<"�੤���੤���੤����"<<endl;}
			if(i==7){cout<<"�੤���੤���੤���੤����"<<endl;}
			if(i==8){cout<<"�੤���੤���੤���੤���੤����"<<endl;}
			if(i==9){cout<<"�੤���੤���੤���੤���੤���੤����"<<endl;}
			w--;
		}
	}
	cout << "  �������ة����ة���";
	if(i==3){cout<<"��"<<endl;}
	if(i==4){cout<<"�ة�����"<<endl;}
	if(i==5){cout<<"�ة����ة�����"<<endl;}
	if(i==6){cout<<"�ة����ة����ة�����"<<endl;}
	if(i==7){cout<<"�ة����ة����ة����ة�����"<<endl;}
	if(i==8){cout<<"�ة����ة����ة����ة����ة�����"<<endl;}
	if(i==9){cout<<"�ة����ة����ة����ة����ة����ة�����"<<endl;}
	cout << "     1     2     ";
	if(i==3){cout<<"3"<<endl<<endl;}
	if(i==4){cout<<"3     4"<<endl<<endl;}
	if(i==5){cout<<"3     4     5"<<endl<<endl;}
	if(i==6){cout<<"3     4     5     6"<<endl<<endl;}
	if(i==7){cout<<"3     4     5     6     7"<<endl<<endl;}
	if(i==8){cout<<"3     4     5     6     7     8"<<endl<<endl;}
	if(i==9){cout<<"3     4     5     6     7     8     9"<<endl<<endl;}
	select(l,i,s,aa,ab,ac,ad,ae,af,ag,ah,ai,ba,bb,bc,bd,be,bf,bg,bh,bi);
}
void select(int l,int i,int s,int aa,int ab,int ac,int ad,int ae,int af,int ag,int ah,int ai,int ba,int bb,int bc,int bd,int be,int bf,int bg,int bh,int bi){
	int a,b,c,d,e,f,g,h,j, ya=0,yb=0,yc=0,yd=0,ye=0,yf=0,yg=0,yh=0,yi=0;
	a = ask(i, 1);if(a==0){goto end;}
	ya = judge(a, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	do{
		b = ask(i,2);if(b==0){goto end;}
	}while ((b/10)==(a/10)|| (b % 10) == (a % 10));
	yb = judge(b, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	do{
		c = ask(i,3);if(c==0){goto end;}
	}while ((c/10)==(a/10)|| (c % 10) == (a % 10) ||(c/10)==(b/10)|| (c % 10) == (b % 10));
	yc = judge(c, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	if(i==3){goto end;}
	do{
		d = ask(i,4);if(d==0){goto end;}
	}while ((d/10)==(a/10)|| (d % 10) == (a % 10) ||(d/10)==(b/10)|| (d % 10) == (b % 10)||(d/10)==(c/10)|| (d % 10) == (c % 10));
	yd = judge(d, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	if(i==4){goto end;}
	do{
		e = ask(i,5);if(e==0){goto end;}
	}while ((e/10)==(a/10)|| (e % 10) == (a % 10) ||(e/10)==(b/10)|| (e % 10) == (b % 10)||(e/10)==(c/10)|| (e % 10) == (c % 10)||(e/10)==(d/10)|| (e % 10) == (d % 10));
	ye = judge(e, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	if(i==5){goto end;}
	do{
		f = ask(i,6);if(f==0){goto end;}
	}while ((f/10)==(a/10)|| (f % 10) == (a % 10) ||(f/10)==(b/10)|| (f % 10) == (b % 10)||(f/10)==(c/10)|| (f % 10) == (c % 10)||(f/10)==(d/10)|| (f % 10) == (d % 10)||(f/10)==(e/10)|| (f % 10) == (e % 10));
	yf = judge(f, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	if(i==6){goto end;}
	do{
		g = ask(i,7);if(g==0){goto end;}
	}while ((g/10)==(a/10)|| (g % 10) == (a % 10) ||(g/10)==(b/10)|| (g % 10) == (b % 10)||(g/10)==(c/10)|| (g % 10) == (c % 10)||(g/10)==(d/10)|| (g % 10) == (d % 10)||(g/10)==(e/10)|| (g % 10) == (e % 10)||(g/10)==(f/10)|| (g % 10) == (f % 10));
	yg = judge(g, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	if(i==7){goto end;}
	do{
		h = ask(i,8);if(h==0){goto end;}
	}while ((h/10)==(a/10)|| (h % 10) == (a % 10) ||(h/10)==(b/10)|| (h % 10) == (b % 10)||(h/10)==(c/10)|| (h % 10) == (c % 10)||(h/10)==(d/10)|| (h % 10) == (d % 10)||(h/10)==(e/10)|| (h % 10) == (e % 10)||(h/10)==(f/10)|| (h % 10) == (f % 10)||(h/10)==(g/10)|| (h % 10) == (g % 10));
	yh = judge(h, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
	if(i==8){goto end;}
	do{
		j = ask(i,9);if(j==0){goto end;}
	}while ((j/10)==(a/10)|| (j % 10) == (a % 10) ||(j/10)==(b/10)|| (j % 10) == (b % 10)||(j/10)==(c/10)|| (j % 10) == (c % 10)||(j/10)==(d/10)|| (j % 10) == (d % 10)||(j/10)==(e/10)|| (j % 10) == (e % 10)||(j/10)==(f/10)|| (j % 10) == (f % 10)||(j/10)==(g/10)|| (j % 10) == (g % 10)||(j/10)==(h/10)|| (j % 10) == (h % 10));
	yi = judge(j, aa, ab, ac,ad,ae,af,ag,ah,ai, ba, bb, bc,bd,be,bf,bg,bh,bi);
	add(l,ya,yb,yc,yd,ye,yf,yg,yh,yi);
end:
	end(l,i,s,aa,ab,ac,ad,ae,af,ag,ah,ai,ba,bb,bc,bd,be,bf,bg,bh,bi);
}
int ask(int i,int num){
	int ch;
	do{
		cout<<"No."<<num<<"\t";
		cin>>ch;
		if(ch==0){break;}
	} while (ch / 10 < 1 || ch / 10 > i || ch % 10 < 1 || ch % 10 > i);
	return ch;
}
int judge(int x,int aa, int ab, int ac,int ad,int ae,int af,int ag,int ah,int ai,int ba, int bb, int bc,int bd,int be,int bf,int bg,int bh,int bi){
	int y;
	if ((x / 10)==1){
		if ((x % 10) == 1){ y = aa + ba; }
		else if ((x % 10) == 2){ y = ab + ba; }
		else if ((x % 10) == 3){ y = ac + ba; }
		else if ((x % 10) == 4){ y = ad + ba; }
		else if ((x % 10) == 5){ y = ae + ba; }
		else if ((x % 10) == 6){ y = af + ba; }
		else if ((x % 10) == 7){ y = ag + ba; }
		else if ((x % 10) == 8){ y = ah + ba; }
		else if ((x % 10) == 9){ y = ai + ba; }
	}
	else if((x/10)==2){
		if ((x % 10) == 1){ y = aa + bb; }
		else if ((x % 10) == 2){ y = ab + bb; }
		else if ((x % 10) == 3){ y = ac + bb; }
		else if ((x % 10) == 4){ y = ad + bb; }
		else if ((x % 10) == 5){ y = ae + bb; }
		else if ((x % 10) == 6){ y = af + bb; }
		else if ((x % 10) == 7){ y = ag + bb; }
		else if ((x % 10) == 8){ y = ah + bb; }
		else if ((x % 10) == 9){ y = ai + bb; }
	}
	else if((x/10)==3){
		if ((x % 10) == 1){ y = aa + bc; }
		else if ((x % 10) == 2){ y = ab + bc; }
		else if ((x % 10) == 3){ y = ac + bc; }
		else if ((x % 10) == 4){ y = ad + bc; }
		else if ((x % 10) == 5){ y = ae + bc; }
		else if ((x % 10) == 6){ y = af + bc; }
		else if ((x % 10) == 7){ y = ag + bc; }
		else if ((x % 10) == 8){ y = ah + bc; }
		else if ((x % 10) == 9){ y = ai + bc; }
	}
	else if((x/10)==4){
		if ((x % 10) == 1){ y = aa + bd; }
		else if ((x % 10) == 2){ y = ab + bd; }
		else if ((x % 10) == 3){ y = ac + bd; }
		else if ((x % 10) == 4){ y = ad + bd; }
		else if ((x % 10) == 5){ y = ae + bd; }
		else if ((x % 10) == 6){ y = af + bd; }
		else if ((x % 10) == 7){ y = ag + bd; }
		else if ((x % 10) == 8){ y = ah + bd; }
		else if ((x % 10) == 9){ y = ai + bd; }
	}
	else if((x/10)==5){
		if ((x % 10) == 1){ y = aa + be; }
		else if ((x % 10) == 2){ y = ab + be; }
		else if ((x % 10) == 3){ y = ac + be; }
		else if ((x % 10) == 4){ y = ad + be; }
		else if ((x % 10) == 5){ y = ae + be; }
		else if ((x % 10) == 6){ y = af + be; }
		else if ((x % 10) == 7){ y = ag + be; }
		else if ((x % 10) == 8){ y = ah + be; }
		else if ((x % 10) == 9){ y = ai + be; }
	}
	else if((x/10)==6){
		if ((x % 10) == 1){ y = aa + bf; }
		else if ((x % 10) == 2){ y = ab + bf; }
		else if ((x % 10) == 3){ y = ac + bf; }
		else if ((x % 10) == 4){ y = ad + bf; }
		else if ((x % 10) == 5){ y = ae + bf; }
		else if ((x % 10) == 6){ y = af + bf; }
		else if ((x % 10) == 7){ y = ag + bf; }
		else if ((x % 10) == 8){ y = ah + bf; }
		else if ((x % 10) == 9){ y = ai + bf; }
	}
	else if((x/10)==7){
		if ((x % 10) == 1){ y = aa + bg; }
		else if ((x % 10) == 2){ y = ab + bg; }
		else if ((x % 10) == 3){ y = ac + bg; }
		else if ((x % 10) == 4){ y = ad + bg; }
		else if ((x % 10) == 5){ y = ae + bg; }
		else if ((x % 10) == 6){ y = af + bg; }
		else if ((x % 10) == 7){ y = ag + bg; }
		else if ((x % 10) == 8){ y = ah + bg; }
		else if ((x % 10) == 9){ y = ai + bg; }
	}
	else if((x/10)==8){
		if ((x % 10) == 1){ y = aa + bh; }
		else if ((x % 10) == 2){ y = ab + bh; }
		else if ((x % 10) == 3){ y = ac + bh; }
		else if ((x % 10) == 4){ y = ad + bh; }
		else if ((x % 10) == 5){ y = ae + bh; }
		else if ((x % 10) == 6){ y = af + bh; }
		else if ((x % 10) == 7){ y = ag + bh; }
		else if ((x % 10) == 8){ y = ah + bh; }
		else if ((x % 10) == 9){ y = ai + bh; }
	}
	else if((x/10)==9){
		if ((x % 10) == 1){ y = aa + bi; }
		else if ((x % 10) == 2){ y = ab + bi; }
		else if ((x % 10) == 3){ y = ac + bi; }
		else if ((x % 10) == 4){ y = ad + bi; }
		else if ((x % 10) == 5){ y = ae + bi; }
		else if ((x % 10) == 6){ y = af + bi; }
		else if ((x % 10) == 7){ y = ag + bi; }
		else if ((x % 10) == 8){ y = ah + bi; }
		else if ((x % 10) == 9){ y = ai + bi; }
	}
	return y;
}
void add(int l,int ya,int yb,int yc,int yd,int ye,int yf,int yg,int yh,int yi){
	if(l==0){cout<<"\t\tnow S=";}else{cout<<"\t\t���� S=";}
	cout<<ya+yb+yc+yd+ye+yf+yg+yh+yi<<endl;
}
void end(int l,int i,int s,int aa,int ab,int ac,int ad,int ae,int af,int ag,int ah,int ai,int ba, int bb, int bc,int bd,int be,int bf,int bg,int bh,int bi){
	char n;
	do{
		if(l==0){cout<<endl<< "try again<y/r/q>?";}else{cout<<endl<<"����һ��<y/r/q>?";}
		cin >> n;
	} while (n != 'y'&&n != 'q'&&n != 'Y'&&n != 'Q'&&n!='r'&&n!='R');
	if (n == 'y' || n == 'Y'){ system("cls");show(l,i,s,aa,ab,ac,ad,ae,af,ag,ah,ai,ba,bb,bc,bd,be,bf,bg,bh,bi); }
	if (n == 'q' || n == 'Q'){ system("cls"); }
	if (n == 'r' || n == 'R'){ system("cls");top(l,i,s); }
}