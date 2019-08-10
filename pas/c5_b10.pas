var     a:array [1..100] of longint;
        i,n,j,tam,dem:longint;
begin
        write('nhap so phan tu ');
        readln(n);
        dem:=0;
        for i:=1 to n do
        begin
        write('nhap gia tri');
        readln(a[i]);
        end;
        for i:=1 to n do
        for j:=n downto i do
        if a[i]>a[j] then
        begin
                tam:=a[i];
                a[i]:=a[j];
                a[j]:=tam;
        end;
        for i:=1 to n-1 do
        if a[i]<>a[i+1] then dem:=dem+1;
        write('so chu so khac nhau trong mang la:',dem+1);
        readln
end.
