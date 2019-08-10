const
        fi='matmath.inp';
        fo='matmath.out';
var
        a,l:array [0..501,0..501] of longint;
        n,m,i,j,mx:longint;
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
function max(a,b,c:longint):longint;
begin
        if (a>=b) and (a>=c) then max:=a;
        if (b>=a) and (b>=c) then max:=b;
        if (c>=a) and (c>=b) then max:=c;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        for i:=2 to m-1 do
                l[i,1]:=a[i,1];
        for i:=2 to n do
                l[1,i]:=a[1,i]+max(0,l[1,i-1],l[2,i-1]);
        for i:=2 to n do
                l[m,i]:=a[m,i]+max(0,l[m,i-1],l[m-1,i-1]);
        for j:=2 to n do
                for i:=1 to m do
                        l[i,j]:=max(l[i-1,j+1],l[i,j+1],l[i+1,j+1])+a[i,j];
        mx:=-maxlongint;
        for i:=1  to n do
                if l[i,n]>=mx then mx:=l[i,n];
        write(f,mx);
        close(f);
end;
begin
        nhap;
        xuly;
        for i:=1 to m do
        begin
                for j:=1 to n do
                        write(l[i,j],' ');
                writeln;
        end;
        readln;
end.