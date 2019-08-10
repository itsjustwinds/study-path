var     a:array [1..100] of longint;
        b:array [1..100] of longint;
        c:array [1..100] of longint;
        i,j,n,m,dem,tam:longint;
begin
        write('nhap so luong cac phan tu cua mang a');
        readln(n);
        dem:=0;
          for i:=1 to n do
        begin
        write('nhap gia tri a:');
        readln(a[i]);
        end;
        write('nhap so luong cac phan tu cua mang b');
        readln(m);
        for j:=1 to m do
        begin
        write('nhap gia tri cua b:');
        readln(b[j]);
        end;
        for i:=1 to n do
        for j:=1 to m do
        if a[i]=b[j] then
        begin
        dem:=dem+1;
        c[dem]:=a[i];
        end;
        for i:=1 to dem do
        for j:=dem downto i do
        if c[i]>c[j] then
        begin
                tam:=c[i];
                c[i]:=c[j];
                c[j]:=tam;
        end;
        write('cac phan tu giao nhau la:');
        for i:=1 to dem do
        if c[i]<>c[i+1] then write(c[i],' ');
        readln
end.