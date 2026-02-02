#include <iostream>
#include <string>
using namespace std;


class Appendable {
        int* array;
        int size;
        int top;

        void make_space(){
                int* array2 = new int[size * 2];
                for (int i = 0; i < size; i++){
                        array2[i] = array[i];
                }
                delete [] array;
                array = array2;
                size = size * 2;
        }

        public:
        Appendable(){
                size = 3;
                array = new int[size];
                top = -1;
        }

        int get(int index){
                if (index < 0 or index > top){
                        cout << index << " is an invalid index" << endl;
                        return -1;
                }
                else {
                        return array[index];
                }
        }

        void append(int x){
                if (top + 1 >= size){
                        make_space();
                }
                top++;
                array[top] = x;
        }

        int count(){
                return top + 1;
        }

        void set(int index, int x){
                if (index < 0 or index > top){
                        cout << index << " is an invalid index" << endl;
                        return;
                }
                else {
                        array[index] = x;
                }
        }

        string as_string() {
                string result = "[ ";
                for (int i = 0; i < size; i++){
                        if (i <= top){
                                result += to_string(array[i]);
                        }
                        else {
                                result += "-";
                        }
                        result += " ";
                }
                result += "]";
                return result;
        }

        ~Appendable(){
                delete [] array;
        }
};

int main() {
        Appendable nums;
        bool quit = false;
        cout << "Enter Appendable Commands" << endl;
        while (!quit) {
                string cmd = "quit";
                cin >> cmd;
                if (cmd == "append") {
                        int x;
                        cin >> x;
                        nums.append(x);
                }
                else if (cmd == "get") {
                        int i;
                        cin >> i;
                        cout << nums.get(i) << endl;
                }
                else if (cmd == "set") {
                        int i;
                        cin >> i;
                        int x;
                        cin >> x;
                        nums.set(i, x);
                }
                else if (cmd == "count") {
                        cout << "count: " << nums.count() << endl;
                } else if (cmd == "string") {
                        cout << nums.as_string() << endl;
                }
                else if (cmd == "quit") {
                        quit = true;
                }
        }
        cout << "Goodbye!" << endl;
        return 0;
}
