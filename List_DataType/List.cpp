#include <iostream>
using namespace std;
template<class T>
class List{
    private:
        T* list;
        size_t size;
    public:
        //create an array with size "n"
        List(size_t n){
 
            list = (T*)malloc(n*sizeof(T));
            size = n;
        }


        

        // initialization of the array with only values
        List(initializer_list<T> lists){
            list = (T*)malloc(100*sizeof(T));
            size_t i = 0,n = 0;
            for (auto element:lists){
                list[i] = element;
                i++; n++;
            }
            size = n;
        }

        
        ~List(){ 
            delete[] list; 
        }


        //destroy the object and prints a string (argument)
        void kill(string s){
            delete[] list;
            std::cout << s << std::endl;
        }


        //return the length of the list
        size_t length(){ return size;}        


        //insert an element  at "index" position
        void in(size_t index, T data){
            list[index] = data;
        }


        //insert an element  at "index" position and shift all the others
        void insert(size_t index, T data){
            T* ptr = new T[size+1];
            
            for (size_t i = 0; i < index; i++)
            {   
                ptr[i] = list[i];
            }
            
            for (size_t i = index; i < size; i++)
            {
                ptr[i+1] = list[i];
            }

            ptr[index] = data;
            list = ptr;
            size++;
        }


        //return the element at one particular index, standard access to indexes
        T at(size_t index){
            return list[index];
        }
    

        //add to the list "howmuch" positions
        void expand(size_t howmuch){
            T* ptr  = list;
            size = size + howmuch;
            T* punt2 =  new T[size];
            for (size_t i = 0; i < size; i++)
            {
                ptr[i] = list[i];
            }
            ptr = punt2;
            punt2 = nullptr;
        }

        //push data into array
        void push(T data){
            list[size] = data;
            size++;

        }

        //remove the last element
        void pop(){
            size--;
        }
      

        
        //Add an element in the first position
        void add(T data){
            T* ptr = new T[size+1];
            for (size_t i = 0; i < size; i++)
            {
                ptr[i+1] = list[i];
            }
            ptr[0] = data;
            list = ptr;
            size++; 
        }

        //remove the first position and shift all the element
        void shift(){
            T* ptr = new T[size-1];
            for (size_t i = 0; i < size; i++)
            {
                ptr[i] = list[i+1];
            }
            list = ptr;
            size--;
        } 



        //initialization of the array (with size declared) 
        void init(initializer_list<T> list){
            int pos = 0;
            for (auto element:list){
                in(pos,element);
                pos++;
            }
        }


        //clear the list
        void clear(){
            std::fill_n(list, size, 0);
        }

        //check if some data is in the list
        int is_in(T data){
            for (size_t i = 0; i < size; i++)
            {
                if(list[i] == data) return i ;
            }
            return -1;
        }    

        //print the list
        void display(){ 
            for (size_t i = 0; i < size; i++)
            {
                std::cout << "[" << i << "]: "<< list[i] << std::endl;
            }
        }
        T operator[](int index)
        {          
            int a = get(index);
            return a;
        }
};



