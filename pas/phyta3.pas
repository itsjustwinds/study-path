const
        fi='phyta3.inp';
        fo='phyta3.out';
var
        x:array [1..19] of longint;
        n,i,a,b,c,dem:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,x[i]);
        close(f);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
        begin
                dem:=0;
                for a:=1 to x[i] do
                        for b:=a to x[i] do
                                for c:=b to x[i] do
                                        if a*a*a+b*b*b+c*c*c=x[i]*x[i]*x[i] then
                                        begin
                                                inc(dem);
                                                writeln(f,a,' ',b,' ',c);
                                        end;
                if dem=0 then writeln(f,'0');
        end;
        close(f);
end;
begin
        nhap;
        xuat;
end.