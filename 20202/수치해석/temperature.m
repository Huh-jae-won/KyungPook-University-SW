function T = temperature(tMean,tPeak,tStart,tLast);
    w = 2*pi/365;
    time = tStart:tLast;
    t = tMean + (tPeak-tMean)*cos(w*(time-205));
    T = mean(t);
end