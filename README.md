# print triangle test

## usage

```bash
Usage: ./print_triangle <options> ...
Options:
  -h,--help  -- Show this help message.
  -l TRIANGLE_LINES,--line=TRIANGLE_LINES -- Lines of triangle to print.
```

## make

```bash
$ make
$ make clean
$ make lint
```

## output

> $ ./print_triangle -l 20

```
                   *                   
                  ***                  
                 *****                 
                *******                
               *********               
              ***********              
             *************             
            ***************            
           *****************           
          *******************          
         *********************         
        ***********************        
       *************************       
      ***************************      
     *****************************     
    *******************************    
   *********************************   
  ***********************************  
 ************************************* 
***************************************
```