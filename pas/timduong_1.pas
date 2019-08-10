const
        fi='timduong.inp';
        fo='timduong.out';
var
        a,l:array [0..501,0..501] of longint;
        n,m,i,j,t,min:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,m,n);
        for i:=1 to m do
                for j:=1 to n do
                        read(f,a[i,j]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[1,1]:=a[1,1];
        for i:=2 to m-1 do
                l[i,1]:=l[i-1,1]+a[i,1];
        for j:=2 to n do
                l[1,j]:=l[1,j-1]+a[1,j];
        for i:=1 to m-1 do
                for j:=1 to n do
                        if l[i-1,j]>l[i,j-1] then l[i,j]:=l[i-1,j]+a[i,j]
                        else l[i,j]:=l[i,j-1]+a[i,j];
        min:=-maxlongint;
        for i:=1 to n do
        begin
                l[m,i]:=l[m-1,i]+a[m,i];
                if l[m,i]>min then min:=l[m,i];
        end;
        write(f,min);
        close(f);
end;
begin
        nhap;
        xuly;
end.