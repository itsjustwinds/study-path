const
        fi='dseq.inp';
        fo='dseq.out';
var
        a,l:array[1..1000000] of longint;
        n,i,j,kq:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                readln(f,a[i]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[1]:=1;
        for i:=2 to n do
                for j:=1 to i-1 do
                if (a[i] mod a[j]=0) and (l[j]+1>l[i]) then l[i]:=l[j]+1;
        kq:=l[1];
        for i:=1 to n do
                if l[i]>kq then kq:=l[i];
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuly;
end.
                if
