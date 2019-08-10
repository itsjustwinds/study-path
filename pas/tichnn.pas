
const
        fi='tichnn.inp';
        fo='tichnn.out';
var
        a:array [1..10000000] of longint;
        kq1,kq2,kq:int64;
        n,i:longint;
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
procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                dec(j);
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
procedure xuat;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        kq1:=a[1]*a[2]*a[3];
        kq2:=a[1]*a[n-1]*a[n];
        if kq1<kq2 then kq:=kq1
        else kq:=kq2;
        write(f,kq);
        close(f);
end;
begin
        nhap;
        xuat;
end.

