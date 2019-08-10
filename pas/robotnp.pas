const
        fi='robotnp.inp';
        fo='robotnp.out';
var
        a,l:array [0..16,0..16] of longint;
        n,j,i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                for j:=1 to n do
                        read(f,a[i,j]);
        close(f);
end;
function max(a,b:longint):longint;
begin
        if a>b then max:=a
        else max:=b;
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
                for j:=1 to n do
                        l[i,j]:=max(l[i-1,j],l[i,j-1]) shl 1+a[i,j];
                write(f,l[n,n]);
               { for i:=1 to n do
                begin
                        for j:=1 to n do
                                write(f,l[i,j],' ');
                        writeln(f);
                end;    }
close(f);
end;
begin
        nhap;
        xuat;
end.