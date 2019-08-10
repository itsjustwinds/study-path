const
        fi='robotnv.inp';
        fo='robotnv.out';
var
        a,l:array [1..1001,1..1001] of longint;
        m,n,i,j,d:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
                for j:=1 to m do
                read(f,a[i,j]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[1,1]:=a[1,1];
        for j:=2 to n do
                l[j,1]:=l[j-1,1]+a[j,1];
        for j:=2 to m do
                l[1,j]:=l[1,j-1]+a[1,j];
        for i:=2 to n do
                for j:=2 to m do
                if l[i-1,j]>l[i,j-1] then l[i,j]:=l[i-1,j]+a[i,j]
                else l[i,j]:=l[i,j-1]+a[i,j];
        write(f,l[n,m]);
        close(f);
end;
begin
        nhap;
        xuly;
        {for i:=1 to n do
        begin
                for j:=1 to m do
                write(a[i,j],' ');
                writeln;
        end;
        writeln;
        for i:=1 to n do
        begin
                for j:=1 to m do
                write(l[i,j],' ');
                writeln;
        end;
        readln; }
end.