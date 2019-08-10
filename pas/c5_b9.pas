var
        a:array [1..100] of longint;
        i,j,n,tam:longint;
begin
randomize;
writeln('nhap n'); readln(n);
for i:=1 to n do
begin
a[i]:=random(100);
write(a[i],' ');
end;
for i:=1 to n do
for j:=n downto i do
if a[i]<a[j] then
begin
tam:=a[i];
a[i]:=a[j];
a[j]:=tam;
end;
write('so lon thu 2 la ',a[2]);
readln
end.

