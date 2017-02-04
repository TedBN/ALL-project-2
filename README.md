## Repo for global functionality of Europe at WAR;


// checking if free memory is available
double* pvalue  = NULL;
if( !(pvalue  = new double )) {
   cout << "Error: out of memory." <<endl;
   exit(1);

}