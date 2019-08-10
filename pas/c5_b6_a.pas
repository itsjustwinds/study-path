var
        a:array [1..100]of longint;
        i,j,n,tam:longint;
begin
        write('nhap so luong cac phan tu');
        readln(n);
        for i:=1 to n do
        begin
        write('gia tri la:');
        readln(a[i]);
        end;
        for i:=1 to n-1 do
         for j:=i+1 to n do
          if a[i]<a[j] then
            begin
              tam:=a[i];
              a[i]:=a[j];
              a[j]:=tam;
            end;
            for i:=1 to n do
            write(a[i],' ');
            readln
          end.


