function res = val(x)
 res=0;
 for i=1:size(x,2)
  res=res+x(i)*x(i);
 end
 res=sqrt(res);
end