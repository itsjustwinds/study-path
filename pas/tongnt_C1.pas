const fi='tongnt.inp';
      fo='tongnt.out';
var n: longint;
    f:text;
procedure nhap;
begin
    assign(f,fi);
    reset(f);
    readln(f,n);
    close(f);
end;

function nt(n: longint) : boolean;
var i: longint;
begin
nt:=false;
if n<2 then exit;
for i:=2 to trunc(sqrt(n)) do
if n mod i =0 then exit;
nt:=true;
end;


procedure xuly;
var a,b,c: longint;
begin
assign(f,fo);
rewrite(f);
for a:=1 to n do
  for b:=1 to n do
    for c:=1 to n do
       begin
         if (a+b+c=n) and (nt(a)) and (nt(b)) and (nt(c))  and (a<=b) and (b<=c) then
         writeln( f, a,' ',b,' ',c);
       end;
  close(f);
end;


begin
nhap;
xuly;
end.
