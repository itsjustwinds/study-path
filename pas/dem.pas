const
        fi='dem.inp';
        fo='dem.out';
var
        a:array [1..1000000] of longint;
        n,i,j,dem,k,t:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        dem:=0;
        for i:=1 to n-2 do
        begin
                t:=0;
                for j:=i to n do
                begin
                     t:=t+a[i];
                     if t=k then inc(dem);
                end;
        end;
        write(f,dem);
        close(f);
end;
begin
        nhap;
        xuly;
end.