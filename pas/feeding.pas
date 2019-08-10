const
        fi='feeding.inp';
        fo='feeding.out';
var
        a,p:array[0..100000] of int64;
        kq:int64;
        i,n:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
        for i:=1 to n do
                read(f,p[i]);
        close(f);
end;
procedure xuly(h:longint);
var
        min,k,i:longint;
begin
        min:=maxlongint;k:=0;
        for i:=1 to h do
                if p[i]<min then
                begin
                        min:=p[i];
                        k:=i;
                end;
        for i:=k to h do
                kq:=kq+a[i]*p[k];
        if k>0 then xuly(k-1);
end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        kq:=0;
        xuly(n);
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuat;
end.