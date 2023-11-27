#include <chrono>
#include <iostream>
#include <vector>
#include <stdexcept>
// Complete: Additional necessary headers ...
#include <thread>
#include <mutex>


// Complete: write the function split that computes the lower/higher indices 
// for which each thread will be responsible. 
void split(std::size_t nele, std::size_t nthreads, 
  std::vector<std::size_t>& lower, std::vector<std::size_t>& upper) {
    std::size_t chunk_size = nele / nthreads;
    std::size_t remainder = nele % nthreads;

    lower.resize(nthreads);
    upper.resize(nthreads);

    for (std::size_t i = 0; i < nthreads; ++i) {
      lower[i] = i * chunk_size;
      upper[i] = (i + 1) * chunk_size;
    }

    // Distribute the remainder among the threads
    for (std::size_t i = 0; i < remainder; ++i) {
        upper[i]++;
    }
}


// Complete: add dot_product and modify it such that there is no race condition. 
void dot_product(const std::vector<double>& v1, const std::vector<double>& v2, 
  std::size_t lower, std::size_t higher, double* result, std::mutex& mtx) {//mutex
    double sum = 0;
    for (std::size_t i = lower; i < higher; ++i) {
        sum += v1[i] * v2[i];
    }

    std::lock_guard<std::mutex> lock(mtx);
    *result += sum;
}


// Complete: the parallel_dot_product function that computes on nthreads the dot product 
// of v1 and v2 
double parallel_dot_product(const std::vector<double>& v1, const std::vector<double>& v2, 
  std::size_t nthreads) {

  if (v1.size() != v2.size()) throw std::runtime_error("Sizes of v1 and v2 don't match");

  std::size_t nele = v1.size(); 
  double result = 0;
  std::mutex mtx;
 
  // Split 'nele' elements into 'nthreads' part
  std::vector<std::size_t> lower;
  std::vector<std::size_t> higher;
  // lower[i] and higher[i] contains the lower and higher indices
  // for which a given thread will compute the dot product
  split(nele, nthreads, lower, higher);  


  // Complete: start 'nthreads' threads
  // don't forget to pass explicitly a reference to the arrays v1 and v2
  std::vector<std::thread> threads;
  for (std::size_t i=0; i<nthreads; ++i) {
    // start a thread that will compute the dot product between v1 and v2 
    // for indices between lower[i] and higher[i]
    threads.emplace_back(dot_product, std::ref(v1), std::ref(v2), lower[i], higher[i], &result, std::ref(mtx));
  }
  
  // Complete: join the threads with the main thread
  for (auto& thread : threads) {
        thread.join();
  }


  return result;
}


void usage(const char* pname) {
  std::cout << "Incorrect number of arguments" << std::endl;
  std::cout << "Usage: " << pname << " nele nthreads" << std::endl;
  std::cout << "where nele is the number of elements in the random vectors" << std::endl;
  std::cout << "and nthreads is the number of threads to be used" << std::endl;
  exit(1); 
}


int main(int argc, char** argv) {
  if (argc != 3) usage(argv[0]); 

  std::size_t nele = std::stoi(argv[1]); 
  std::size_t nthreads = std::stoi(argv[2]); 

  std::vector<double> v1(nele);
  // complete: fill v1 with random integers
  for (size_t i = 0; i < nele; ++i) {
    v1[i] = double(rand())/double(RAND_MAX);
  }

  std::vector<double> v2(nele);
  for (size_t i = 0; i < nele; ++i) {
    v2[i] = double(rand())/double(RAND_MAX);
  }


  std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  double result = parallel_dot_product(v1, v2, nthreads); 
  std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();

  std::cout << "Result: " << result << " / Elapsed time (ms): " 
            << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() 
            << std::endl;
    
  /*
  // show v1
  std::cout << "v1 elements: "<<std::endl;
  for (const auto& element : v1) {
      std::cout << element << std::endl;
  }
  std::cout << std::endl;

  // show v2
  /*std::cout << "v2 elements: "<<std::endl;
  for (const auto& element : v2) {
      std::cout << element << std::endl;
  }
  std::cout << std::endl;

  std::cout << "check" << std::endl;
  double sum = 0;
  for (int i=0; i<nele; i++){
    double con=v1[i]*v2[i];
    //std::cout << con << std::endl;
    sum += con;
  }
  std::cout << "sum:"<<sum << std::endl;
}*/


// How to exe ↓
// .\a.exe 10000 4