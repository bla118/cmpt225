#include <iostream>
#include <string>
#include <vector>
#include "HashTable.h"
#include "spellcheck.h"
#include "readfile.h"
#include <stdexcept>


using namespace std;

int main()
{
	
	HashTable HT;
	cout << "Constructor underlying size: 11 = " << HT.maxSize() << endl;
	HT.insert("cat");
	HT.insert("how");
	HT.insert("yes");
	HT.insert("aaaaaaaaaaaaaaaaaaaaajhjhjkhjkhkjhjkhkjjkkljhkkjhbbbccghjghkgaaaabaaaaaaaaaaaaaaaaaaaaaaaabbbb");
	HT.insert("supercalifragilisticexpioldoucious");
	HT.insert("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	HT.insert("abcdefghijklmnopqrstuvwxyz");
	HT.insert("aaaaaaaaabbbbbbbbbbbbbcccccccccccccccdddddddddddddeeeeeeeeeee");
	HT.insert("whaaaaaaaaaaaaaaaaaaaaaaaaaaaaaat");
	HT.insert("thisworkssometimes");
	HT.insert("donotunderstandatall");
	HT.insert("whatisthis");
	HT.insert("itazebra");
	HT.insert("itazebra");
	HT.insert("testing");
	HT.insert("whatisthis");
	HT.insert("asldfkjdkfdsfjasdlkfjsdlkfjlaskdjfkajeflwewoafjefiwajeofaweoifaoweifjwioajefwooogoasjdfkasjdfakdf.ajsdfkjasofjeoifjawioefjwioaejfwioaejfwioajefiwajefoaweifjawoefjaioewfjoweijfweiojfoweafiweoafjfowiefweiof");
	HT.insert("adslfkjsdflajweoifjiewasdfjoaweijf");
	HT.insert("adslfkjsdflajweoifjiasdfewfjoadweijf");
	HT.insert("adslfkjsdflajweoifjiewfeasdfdijf");
	HT.insert("adslfkjsdflajweoifjiewfadsfsddfdffadsfsdjoaweijf");
	HT.insert("adslfkjsdflaefefeajweoifjiewfjoawdfdeijf");
	HT.insert("adslfkjsdflajweoifjiewfjoaweijaefefeefaef");
	HT.insert("adslfkjsdflajweoiaefefsfjiewfjoaweijgggf");
	HT.insert("adslfkjsdfasefaesflajweoifjiewfjoaweijhhhf");
	HT.insert("adslfkjsdflajweoifjiewfjoaweijfjjjyjy");
	HT.insert("adslfkjsdflajweoifasefaeaeffajiewfjoakukweijf");
	HT.insert("adslfkasefdjsdflajweoifjiewfjoaweijukukuf");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaadsfewfaefsdfdweijfkukuk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfkukugfhrshrk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfkukukytjtjd");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfkukukaradfsef");
	HT.insert("adslfkjaefsdfdssdflajweoifjiadsfdsfdafdsewfjoaweijfkukuk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfadsfadsgadgdsfakukuk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijdfadfdsfdfkukuk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfkfdgrehryjukuk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfililjlikkukuk");
	HT.insert("adslfkjaefsdfdssdflajweoifjiewfjoaweijfkukukhululhulkuk");
	HT.insert("alsdkfjsdlkfjaefasdeofooofofo");
	HT.insert("alsdkfjefjoaweifjiawefjidfjaoifjaeoiufawoeifuaeiofuweiofasdjfkalsdf");
	HT.insert("adfdfadfsdfdfsdalsdkfjefjoaweifjiawefjidfjaoifjaeoiufawoeifuaeiofuweiofasdjfkalsdf");
	HT.insert("alsdkfjefjoaweefaefegegifjiawefjidfjaoifjaeoiufawoeifuaeiofuweiofasdjfkalsdf");
	HT.insert("alsdkfjefjoaweifjiawefagehrjtjthjidfjaoifjaeoiufawoeifuaeiofuweiofasdjfkalsdf");
	HT.insert("thisisnwefoakjefoajefoawejfkofkjdkfjskdf");
	HT.insert("alsdkfajsdlkfjksdflkdjfaeifjaoweiruaiewruaoiewrerweijfasdfksdfkajfafjafsdfj");
	HT.insert("alkdsjfisefoiajfskdfbdbgbgbgbgbgb");
	HT.insert("bbbbbbbbbbbbbbbbbbadfaesfasfksdfsdfsdfds");
	HT.insert("casdfadsfjdkslfjadskadccccc");
	


	HT.print();
	cout << endl;
	cout << endl << "uderlying size: 23 = " << HT.maxSize() << endl;
	cout << "current size: 8 = " << HT.size() << endl;
	cout << "find(adslfkasefdjsdflajweoifjiewfjoaweijukukuf): 1 = " << HT.find("adslfkasefdjsdflajweoifjiewfjoaweijukukuf") << endl;
	cout << "find(cat) 1 = " << HT.find("cat") << endl;
	cout << "find(whatisthis) 1 = " << HT.find("whatisthis") << endl;
	cout << "find(itazebra) 1 = " << HT.find("itazebra") << endl;

	
	cout << "--------------------------------------------------------------------" << endl;
	
	HashTable cpy;
	cpy.insert("hi");
	cpy.insert("yooo");
	cpy = HT;
	cpy.print();
	cout << endl;

	cout << "underlying size: 23 = " << cpy.maxSize() << endl;
	cout << "current size = " << cpy.size() << endl;
	cout << "find(adslfkasefdjsdflajweoifjiewfjoaweijukukuf): 1 = " << cpy.find("adslfkasefdjsdflajweoifjiewfjoaweijukukuf") << endl;
	cout << "find(yooo) : 0 = " << cpy.find("yooo") << endl;
	cout << "_____________________________________________________________" << endl;
	HashTable t;
	vector<string>dictionary = readFile("wordList1000.txt");
	for(std::vector<string>::const_iterator i = dictionary.begin(); i != dictionary.end(); ++i)
		t.insert(*i);

	t.print();
	cout << "currentSize = " << t.size() << endl;
	cout << "size = " << t.maxSize() << endl;

	int counter = 0;
	for(int i = 0; i < t.maxSize(); i ++)
	{
		if(t.getStr(i) != "")
		{
			counter ++;
		}
	}

	cout << "counter = " << counter << endl;

	cout << "___________________________________________________________________________________________" << endl << endl;

	HashTable spellCheck(3);
	spellCheck.insert("chat");
	spellCheck.insert("hate");
	
	HashTable space;
	space.insert("what");
	space.insert("up");

	vector<string> result = extraLetter(spellCheck, "chate");
	cout << result[0] << endl;
	cout << result[1] << endl;
	
	HashTable transpo;
	transpo.insert("hello");
	vector<string> reult = transposition(transpo, "helol");
	cout << reult[0] << endl;

	vector<string> missSpace = missingSpace(space, "whatup");
	cout << missSpace[0] << endl;

	HashTable mis;
	mis.insert("poet");
	mis.insert("poke");
	mis.insert("pole");
	mis.insert("ooga");
	mis.insert("aloooo");
	vector<string> mislett = missingLetter(mis, "poe");
	cout << mislett[0] << endl;
	cout << mislett[1] << endl;
	cout << mislett[2] << endl;

	HashTable inc;
	inc.insert("shed");
	inc.insert("thee");
	inc.insert("them");
	inc.insert("they");
	inc.insert("thud");
	inc.insert("toed");
	inc.insert("yumm");
	inc.insert("bedh");
	inc.insert("thad");
	inc.insert("thedd");

	vector<string> incressult = incorrectLetter(inc, "thed");
	for(int i = 0; i < 8; i ++)
		cout << incressult[i] << " ";
	cout << endl;
}