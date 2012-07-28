#include <iostream>
using namespace std;

void over_lay(const char* str, int* lay_array) 
{
    int length = 0;
    while(*(str + length)) length++;
    //num is index
    lay_array[0] = -1;
    int index = -1;
    // lay_array[1] = -1;
    //i is the end index
    for (int i = 1; i < length; i++) {
	if (index == -1) {
	    lay_array[i] = (str[0] == str[i]) ? 0 : -1;
	    index = lay_array[i];
	    continue;
	    
	}
//if index != -1;do the following	
	while (index != -1) {
	    
	    if ( str[index + 1] == str[i] ){
		
		lay_array[i] = index + 1;
		index = index + 1;
		
		break;
	    }
	    
	else if(index >= 0){
	    index = lay_array[index];
	}
	}
	if(index == -1) lay_array[i] = -1;
//	cout << index;
    }
}
int kmp(const char* str1, const char* str2)
{
    int index1 = 0;
    int index2 = 0;

    int length1 = 0;
    int length2 = 0;
    while( *(str1 + length1)) length1 ++;
    while( *(str2 + length2)) length2 ++;

    int* lay_array = new int[length2];

    over_lay(str2, lay_array);
    
    while( index1 < length1) {

	if ( *(str1 + index1) == *(str2 + index2)) {
	    index1 ++;
	    index2 ++;
	}
	else if (index2 == length2) return (index1 - length2);
	else if (index2 == 0) index1 ++;
	else {
	    index2 = lay_array[index2] + 1;
	}
    }
    return -1;	
}

int main(int argc, char *argv[])
{
    char string1[] = "abcdabcd";
    char string2[] = "ayyuuiiabcdabcddsadisad";
    int length = 0;
    while ( *(string1 + length)) length++;
    cout << "length:" << length<< endl;
    
    
    int* lay_array = new int[length];
    over_lay(string1, lay_array);

    for (int i = 0; i < length; i++) {

	cout << lay_array[i] << endl;
    }
    cout << "answer is : ";
    
    cout << kmp(string2, string1) << endl;
    delete[] lay_array;
    
    
    return 0;
}
    
