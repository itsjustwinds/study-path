uses math;
var
        a,b:array[1..64,1..64] of longint;
        dai,rong,i,j,k,h,t,d,max,kq,n,m:longint;
procedure nhap;
begin
        readln(n,m,h);
        for i:=1 to n do
                for j:=1 to m do
                        read(a[i,j]);
        for i:=1 to n do
                for j:=1 to m do
                        read(b[i,j]);
end;
procedure xuly;
begin
        max:=0;
        for i:=1 to n do
                for j:=1 to m do
                begin
                        for k:=1 to n do
                                for t:=1 to m do
                                begin
                                        if abs(a[i,j]-b[k,t])<=h then
                                        begin
                                                      dai:=0;rong:=0;
                                                while dai<min((m-j),(m-t)) do
                                                begin
                                                        if abs(a[i,j+dai+1]-b[k,t+dai+1])>h then
                                                                break;
                                                        inc(dai);
                                                end;
                                                while rong<min((n-i),(n-k)) do
                                                begin
                                                        for d:=0 to dai do
                                                        if abs(a[i+rong,j+d]-b[k+rong,t+d])>h then
                                                                break;
                                                        inc(rong);
                                                end;
                                                if (dai+1)*(rong+1)>max then max:=(dai+1)*(rong+1);
                                        end;
                                end;
                end;
        writeln(max);
end;
begin
        assign(input,'htab.inp');
        assign(output,'htab.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
