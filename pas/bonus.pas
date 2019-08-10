var
        a,f:array[0..1000,0..1000] of longint;
        i,j,n,k,m,h,c:longint;
        kq:int64;
procedure nhap;
begin
        readln(n,k);
        for i:=1 to n do
                for j:=1 to n do
                        read(a[i,j]);
end;
procedure xuly;
var     tmp:longint;
begin
        for i:=1 to n do
                for j:=1 to n do
                        f[i,j]:=f[i-1,j]+f[i,j-1]-f[i-1,j-1]+a[i,j];
        for i:=1 to n-k+1 do
                for j:=1 to n-k+1 do
                begin
                        c:=f[i+k-1,j+k-1]-f[i+k-1,j-1]-f[i-1,j+k-1]+f[i-1,j-1];
                        if c>kq then kq:=c;
                end;
        writeln(kq);
end;
begin
        {assign(input,'bonus.inp');
        assign(output,'bonus.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output); }
end.