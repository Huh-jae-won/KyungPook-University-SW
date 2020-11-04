function approxiSin(x,n)
    true = sin(x);
    cnt = 1;
    while (1)
        approxi = 0;
        for i=1:1:cnt
            approxi = approxi + power(-1,i+1)*power(x,2*i-1)/factorial(2*i-1);
        end
        err = (true-approxi)/true*100;
        fprintf('%3d %14.10f %14.10f %12.8f\n',cnt,true,approxi,err)
        cnt = cnt+ 1;
        if cnt>n
            break;
        end
    end
end