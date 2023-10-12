/*s1290139*/
// test_pointers.cpp
// COMPLETE include necessary headers
#include<iostream>
int main(void)
{
  // 1. Declare a variable f as a pointer to a float
  float* f;
  // 2. Create a float variable named e, and store the value 2.71828f
  float e = 2.71828f;
  // 3. Make f points to e
  f = &e;
  // 4. Print out the content of the memory location pointed to by f
  std::cout<<"f : "<<*f<<std::endl;
  short a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  // 5. Declare a variable ip as a pointer to a short integer
  short* ip;
  // 6. Make ip points to the beginning of the array a
  ip = a;
  // 7. Print out what ip points to and the content of a[0] (verify they are the same)
  std::cout<<"ip : "<<*ip<<" a[0] : "<<a[0]<<std::endl;
  // 8. Increase ip by 3 and check that what it points to corresponds to a[3]
  ip = ip+3;
  std::cout<<"increased ip : "<<*ip<<", a[3] : "<<a[3]<<std::endl;
  // 9. Make ip points to the last element of the array
  ip=&a[9];

  int n = 20;
  // 10. Declare a variable fa as a pointer to float and 
  // make it point to an array of "n" element of type "float" created on the heap
  float* fa = new float[n];
  // 11. Store the values i / 5.0f for i from 0 to n-1 in this array 
  for(int i=0;i<=n-1; i++){
    fa[i]=static_cast<float>(i)/5.0f;
  }
  // 12. Print out each element of fa
  for(int i=0;i<=n-1;i++){
    std::cout<<"fa["<<i<<"] : "<<fa[i]<<std::endl;
  }
  // 13. Delete the previously allocated memory
  delete[] fa;

  //
  int m = 5;
  n = 10;
  double** dd;
  // 14. Allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n).  
  // Make dd points to this 2d array.
  dd = new double* [m];
  for(int i=0;i<m;i++){
    dd[i]=new double[n];
  }
  // 15. Set the element dd[i][j] to be equal to double(i)+double(j)+1
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        dd[i][j]=double(i)+double(i)+double(j)+1;
    }
  }
  // 16. Delete the memory allocated for the 2d array
  for(int i=0;i<m;i++){
    delete[] dd[i];
  }
  delete[] dd;
  // 17. Create a reference to the variable f (1. above). Name it rf
  float& rf =e;
  // 18. Assign the value 3.14159f to rf 
  rf = 3.14159f;
  // 19. Print out the value of f and rf and verify that they are equal

  std::cout<<"f: "<< e <<", rf: "<<rf<<std::endl;

  return 0;
}