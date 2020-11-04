function cylinder(r,L,plot_title)
    h = linspace(0,2*r);
    V = (power(r,2).*acos((r-h)/r)-(r-h).*sqrt(2*r.*h-power(h,2)))*L;
    plot(h,V);
    title(plot_title);
end