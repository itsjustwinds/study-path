var
        a:array [1..100]of longint;
        i,j,n,tam,x,k:longint;
begin
        write('nhap so luong cac phan tu');
        readln(n);
        for i:=1 to n do
        begin
        write('gia tri la:');
        readln(a[i]);
        end;
        write('nhap x:');
        readln(x);
        for i:=1 to n-1 do
         for j:=i+1 to n do
          if a[i]<a[j] then
            begin
              tam:=a[i];
              a[i]:=a[j];
              a[j]:=tam;
            end;
            for i:=1 to n do
            if x>a[i] then
            begin
            k:=i;
            break;
            end;
            for i:=n downto k do a[i+1]:=a[i];
            a[k]:=x;
            for i:=1 to n+1 do
            write(a[i],' ');
            readln
          end.


