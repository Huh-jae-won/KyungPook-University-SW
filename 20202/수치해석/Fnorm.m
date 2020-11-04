function [NormNested, NormSum ] = Fnorm(x)
    cnt = numel(x);
    NormNested = 0;
    for i=1:1:cnt
        NormNested = NormNested + power(x(i),2);
    end
    NormNested = sqrt(NormNested);
    NormSum = sqrt(sum(sum(x.^2,1),2));
end