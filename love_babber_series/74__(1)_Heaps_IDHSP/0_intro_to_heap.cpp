// heap is a c.b.t with heap properties(max_heap or min_heap)

// conditions for heap------1. C.B.T
//                          2. ethier max order or min order

// REPRESENTATION OF HEAP-----heap is represented as array(due to c.b.t)
//                                                         ----in which 

//                                                         ----in case(0th index)
//                                                         ----leftchild_index=2*i+1;
//                                                         ----rightchild_index=2*i+2;
//                                                         ----parent_index=floor of i-1/2;

//                                                         ----in case(1th index)
//                                                         ----leftchild_index=2*i+0;
//                                                         ----rightchild_index=2*i+1;
//                                                         ----parent_index=floor of i/2;