#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

using namespace std;


// Complete the findNumber function below.

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
#if 0
char* findNumber(int arr_count, int* arr, int k) {
	int i = 0;
	for (i = 0; i < arr_count; i++) {
		if (k == arr[i]) {
		    return  "YES"; 
		}
	}
	
	return "NO";
}
#endif

class runtime_error222 : public exception {
public:
  /*due to it has constructer function, so it has no defaulr "runtime_error() function, you must specify yourself"*/
  explicit runtime_error222 (const string& what_arg); /*const--> not allow here in constructors*/
};

class Rest2{
public:
  Rest2();
 ~Rest2();
private:
};


void test() {
	int v1 = 42;
	auto f = [&]() mutable {cout<<v1<<endl;return v1;};
	v1 = 0;
	cout<<v1<<endl;
	auto j = f();

	cout<<j<<endl;
}
int main()
{
   cout<<"a"<<endl;	
 try {
 //  throw 2; --> if this used, later throw will be execuated.
  // throw exception("BAD CASE TEST"); -->exception class does not support this constructer
  // throw runtime_error; //BAD CASE: no default construct for runtime_error() due to it has construct funtions already..
   throw runtime_error("HERE\n"); //ok.
   throw; //this line means any catch , includes catch(..) also cannot catches it, then program will abort() abnormally. 
} catch (int) {
   cout<<"catched!"<<endl;
} catch(exception & e) {  //WARNING: HERE CATCHED, maybe runtime_error, runtime_error222 CANNOT BE CAUGHT THEN.
   cout<<"catched 2\n"<<e.what()<<endl;	
} catch (runtime_error  e2) {
   cout<<"catched 3,"<<e2.what()<<endl;
} catch (runtime_error222 & e3) {
   cout<<"catched 4"<<e3.what()<<endl;	
} catch (...) {
   cout<<"catched 5"<<endl;
  }
  
   cout<<"b"<<endl;	
   test();	
    return 0;		
}
#if 0
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* arr_count_endptr;
    char* arr_count_str = ltrim(rtrim(readline()));
    int arr_count = strtol(arr_count_str, &arr_count_endptr, 10);

    if (arr_count_endptr == arr_count_str || *arr_count_endptr != '\0') { exit(EXIT_FAILURE); }

    int* arr = malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++) {
        char* arr_item_endptr;
        char* arr_item_str = ltrim(rtrim(readline()));
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    char* k_endptr;
    char* k_str = ltrim(rtrim(readline()));
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    printf("findNumber: arr_count=%d, k = %d,", arr_count, k);	 
    
    int loop = 0;
    for (loop = 0; loop < arr_count; loop++)	
    	printf("arr[%d] = %d, ", arr[loop]);
    
    printf("\n");		
    
    char* res = findNumber(arr_count, arr, k);
   
    printf("res: %s\n", res);
    fprintf(fptr, "%s\n", res);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}
#endif
