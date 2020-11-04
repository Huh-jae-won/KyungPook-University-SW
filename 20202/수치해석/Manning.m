function Manning()
    n = [0.036 ; 0.020 ; 0.015 ; 0.030 ; 0.022];
    S = [0.0001 ; 0.0002 ; 0.0012 ; 0.0007 ; 0.0003];
    B = [10 ; 8 ; 20 ; 25 ; 15];
    H = [2 ; 1 ; 1.5 ; 3 ; 2.6];
    U = sqrt(S)./n.*power(B.*H./(B+2*H),2/3);
    size = 5;
    fprintf('  n        S      B      H        U\n');
    for i=1:5
        fprintf("%5.3f\t%6.4f\t%5.2f\t%4.2f\t%6.4f\n",n(i),S(i),B(i),H(i),U(i));
    end

end