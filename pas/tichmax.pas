const
        fi='tichmax.inp';
        fo='tichmax.out';
var
        a:array [1..10000] of longint;
        t1,t2,t,i,j,tam,n,h,k:longint;
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
        t1:=1;
        t2:=1;
        t:=1;
        for i:=1 to n-1 do
                for j:=2 to n do
                        if a[i]<a[j] then
                        begin
                                tam:=a[i];
                                a[i]:=a[j];
                                a[j]:=tam;
                        end;
         h:=a[1]*a[2]*a[3];
         k:=a[1]*a[n-1]*a[n];
         if h>=k then t1:=h
         else t1:=k;
         h:=a[n]*a[n-1]*a[1];
         k:=a[n]*a[1]*a[n-1];
         if h>=k then t2:=h
         else t:=k;
         if t1>=t2 then t:=t1
         else t:=t2;
         write(f,t);
         close(f);
end;
begin
        nhap;
        xuly;
end.