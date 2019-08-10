const
        fi='cocnhay.inp';
        fo='cocnhay.out';
var
        a,l:array[0..100001] of longint;
        i,j,k,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to k do
                read(f,a[i]);
        close(f);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        l[0]:=0;
        for i:=1 to n do
        begin
                l[i]:=0;
                for j:=1 to k do
                        if i>=a[j] then
                                if i-a[j]=0 then
                                l[i]:=l[i]+l[i-a[j]]+1
                                else l[i]:=l[i]+l[i-a[j]];
                l[i]:=l[i] mod 123456789;
        end;
        write(f,l[n]);
        close(f);
end;
begin
        nhap;
        xuly;
end.
