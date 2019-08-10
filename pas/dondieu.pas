const
        fi='dondieu.inp';
        fo='dondieu.out';
var
        a,l:array [1..100000] of longint;
        i,n,dem,vt:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        close(f);
end;
procedure xuly;

begin
        assign(f,fo);
        rewrite(f);
        l[1]:=1;
        dem:=1;
        for i:=2 to n do
        begin
                if a[i]>=a[i-1] then l[i]:=l[i-1]+1
                else l[i]:=1;
        end;
        for i:=1 to n do
                if l[i]>dem then
                begin
                        vt:=i;
                        dem:=l[i];
                end;
        writeln(f,dem);
        for i:=vt-dem+1 to vt do
                write(f,a[i],' ');
        close(f);
end;
begin
        nhap;
        xuly;
end.