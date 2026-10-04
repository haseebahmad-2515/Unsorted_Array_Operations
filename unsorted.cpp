#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

bool findKthLargest(const int *arr, int n, int k, int &val)
{
    // if (k-1) elements are greator than that element return true and val=arr[i]; if 5th largest exactly 4 elements are greator than that
    // time o(n^2)  space =o(1)

    if (k < 1 || k > n)
    {
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        int greatorcount = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                greatorcount++;
            }
        }
        if (greatorcount == k - 1)
        {
            val = arr[i];
            return true;
        }
    }

    return false;
}

class unsortedlist
{
private:
    int *array;
    int maxsize;
    int currsize;

public:
    unsortedlist(int size = 0)
    { // constructor
        maxsize = size;
        currsize = 0;
        array = new int[maxsize];
        for (int i = 0; i < maxsize; i++)
        {
            array[i] = 0;
        }
    }
    unsortedlist(const unsortedlist &obj)
    { // copyconstructor task4
        maxsize = obj.maxsize;
        currsize = obj.currsize;
        array = new int[obj.maxsize];
        for (int i = 0; i < obj.currsize; i++)
        {
            array[i] = obj.array[i];
        }
    }
    unsortedlist &operator=(const unsortedlist &obj1)
    { // task4
        if (this == &obj1)
        { // self assignmen t check
            return *this;
        }
        delete[] array; // deletion
        array = nullptr;

        maxsize = obj1.maxsize; // deep
        currsize = obj1.currsize;
        array = new int[obj1.maxsize];
        for (int i = 0; i < obj1.currsize; i++)
        {
            array[i] = obj1.array[i];
        }
        return *this;
    }
    bool operator==(const unsortedlist &other)
    {
        if (maxsize != other.maxsize || currsize != other.currsize)
        {
            return false;
        }
        for (int i = 0; i < currsize && i < other.currsize; i++)
        {
            if (array[i] != other.array[i])
            {
                return false;
            }

            return true;
        }

        cout << "these two data structures are equal" << endl;
        return true;
    }
    ~unsortedlist()
    { // destructor
        delete[] array;
        array = nullptr;
    }
    void display()
    { // display func
        if (currsize == 0)
        {
            cout << "This data structure array is empty" << endl;
        }
        else
        {
            cout << "The current array elements are" << endl;
            for (int i = 0; i < currsize; i++)
            {
                cout << array[i] << " ";
            }
        }
    }
    bool isempty()
    { // isempty func
        if (currsize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    { // isfull func
        if (currsize == maxsize)
        {
            cout << "list is full" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool insertelement(int val)
    { // insertion in an array
        if (isfull())
        {
            cout << "The list is full" << endl;
            return false;
        }
        else
        {
            array[currsize] = val;
            currsize++;
            return true;
        }
    }
    int isremoveall1(int val)
    { // removal one overwrite
        int removed1 = 0;
        for (int i = 0; i < currsize;)
        {
            if (array[i] == val)
            {
                array[i] = array[currsize - 1];
                currsize--;
                removed1++;
            }
            else
            {
                i++;
            }
        }
        return removed1;
    }
    int isremoveall2(int val)
    { // removal two shifting method
        int removed2 = 0;
        for (int i = 0; i < currsize;)
        {
            if (array[i] == val)
            {
                for (int j = i; j < currsize - 1; j++)
                {
                    array[j] = array[j + 1];
                }
                currsize--;
                removed2++;
            }
            else
            {
                i++;
            }
        }
        return removed2;
    }
    int isremoveall3(int val)
    {
        int newsize = 0;
        int removed3 = 0;
        int *temp = new int[currsize];
        for (int i = 0; i < currsize; i++)
        {
            if (array[i] != val)
            {
                temp[newsize] = array[i];
                newsize++;
            }
            else
            {
                removed3++;
            }
        }
        delete[] array;
        currsize = newsize;
        array = temp;
        return removed3;
    }
    int isremoveall(int val)
    { // task4
        int count = 0;
        int j = 0;
        for (int i = 0; i < currsize; i++)
        {
            if (array[i] == val)
            {
                count++;
            }
            else
            {
                array[j] = array[i];
                j++;
            }
        }
        currsize = currsize - count;
        return count;
    }
    bool getval(int index, int &val)
    {
        if (index < 0 || index >= currsize)
        {
            return false; // invalid index
        }

        val = array[index];
        return true;
    }
    bool search(int key)
    {

        for (int i = 0; i < currsize; i++)
        {
            if (array[i] == key)
            {

                return true;
            }
        }
        return false;
    }
    int replaceval(int oldval, int newval)
    {
        int temp;
        int count = 0;
        for (int i = 0; i < currsize; i++)
        {
            if (array[i] == oldval)
            {
                temp = array[i];
                array[i] = newval;
                newval = temp;
                count++;
            }
        }

        return count;
    }

    void reverse()
    {

        for (int i = 0; i < currsize / 2; i++)
        {
            swap(array[i], array[currsize - 1 - i]);
        }
    }

    int replace(int oldval, int newval)
    {
        int count = 0;
        for (int i = 0; i < currsize; i++)
        {
            if (array[i] == oldval)
            {
                swap(array[i], newval);
                count++;
            }
        }
    }

    void combine(const unsortedlist &obj)
    {
        int newz = 0;
        int newcap = maxsize + obj.maxsize;
        int newsize = currsize + obj.currsize;
        int *temp = new int[newcap];
        for (int i = 0; i < currsize; i++)
        {
            temp[newz] = array[i];
            newz++;
        }
        for (int i = 0; i < obj.currsize; i++)
        {
            temp[newz] = obj.array[i];
            newz++;
        }

        if (array != nullptr)
        {
            delete[] array;
            array = nullptr;
        }
        array = temp;
        currsize = newsize;
    }
    int findmax()
    {
        int max = array[0];
        for (int i = 0; i < currsize; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        return max;
    }
    bool removemax(int &maxvalue)
    {

        if (isempty())
        {
            return false;
        }

        int max = array[0];
        int maxindex = 0;
        for (int i = 0; i < currsize; i++)
        {
            if (array[i] > max)
            {
                maxvalue = array[i];
                max = array[i];
                maxindex = i;
            }
        }
        maxvalue = max;
        for (int j = maxindex; j < currsize - 1; j++)
        {
            array[j] = array[j + 1];
        }

        currsize--;
        return true;
    }
    void bubblesort()
    {
        int temp = 0;
        for (int i = currsize - 1; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    void selectionsort()
    {
        int temp = 0;

        for (int i = 0; i < currsize - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < currsize; j++)
            {
                if (array[j] < array[min])
                {
                    min = j;
                }
            }
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    void insertionsort()
    {
        for (int i = 1; i < currsize; i++)
        {
            int val = array[i];
            int j = i - 1;
            while (j >= 0 && val < array[j])
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = val;
        }
    }
    bool removelastoccurances(int val)
    { // do not increment i in else becauswe you wnat only one elment r3wemove
        if (isempty())
        {
            return false;
        }
        for (int i = currsize - 1; i >= 0; i--)
        {
            if (array[i] == val)
            {
                for (int j = i; j < currsize - 1; j++)
                {
                    array[j] = array[j + 1];
                }

                currsize--;
                return true;
            }
        }
        return false;
    }

    unsortedlist intersection(const unsortedlist &list2) const
    {
        unsortedlist newarray(currsize);
        int idx = 0; // local index for newarray

        for (int i = 0; i < currsize; i++)
        {
            int val = array[i];
            for (int j = 0; j < list2.currsize; j++)
            {
                if (list2.array[j] == val)
                {
                    newarray.array[idx++] = val; // cleaner than using currsize
                    break;
                }
            }
        }

        newarray.currsize = idx;
        return newarray;
    }

    bool issubset(const unsortedlist &list2)
    {

        if (currsize == 0)
        {
            return true;
        }
        if (this->currsize > list2.currsize)
        {
            return false;
        }
        for (int i = 0; i < currsize; i++)
        {

            int j;
            for (j = 0; j < list2.currsize; j++)
            {
                if (this->array[i] == list2.array[j])
                    break;
            }

            if (j == list2.currsize)
                return false;
        }

        return true;
    }

    unsortedlist difference(const unsortedlist &list2)
    {
        unsortedlist newarray(currsize); // max possible size = currsize
        int resIdx = 0;                  // local index for newarray

        for (int i = 0; i < currsize; i++)
        {
            int val = array[i];
            bool found = false;

            // Check if val exists in list2
            for (int j = 0; j < list2.currsize; j++)
            {
                if (list2.array[j] == val)
                {
                    found = true;
                    break;
                }
            }

            // If not found in list2, add to newarray
            if (!found)
            {
                newarray.array[resIdx++] = val;
            }
        }

        newarray.currsize = resIdx; // update logical size
        return newarray;
    }

    unsortedlist Union(const unsortedlist &list2)
    {
        int maxSize = currsize + list2.currsize;
        unsortedlist result(maxSize); // allocate max possible space
        int resIdx = 0;               // local index for result

        // Copy all elements from first list
        for (int i = 0; i < currsize; i++)
        {
            result.array[resIdx++] = array[i];
        }

        // Add elements from second list if not already in result
        for (int i = 0; i < list2.currsize; i++)
        {
            int val = list2.array[i];
            bool found = false;

            for (int j = 0; j < resIdx; j++)
            { // only check existing elements
                if (result.array[j] == val)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                result.array[resIdx++] = val;
            }
        }

        result.currsize = resIdx; // update logical size
        return result;
    }
};

int main()
{
    int temp;
    int n = 5;
    /* int*array= new int[n];
     for(int i=0;i<n;i++){
       cin>>array[i];

     } */
    unsortedlist l1(5);
    l1.insertelement(1);
    l1.insertelement(2);
    l1.insertelement(0);
    l1.insertelement(2);
    l1.insertelement(1);
    unsortedlist l2(5);
    l2.insertelement(1);
    l2.insertelement(2);
    l2.insertelement(5);
    l2.insertelement(13);
    l2.insertelement(9);
    l1.display();
    cout << endl;
    l1.insertionsort();
    l1.display();

    return 0;
}