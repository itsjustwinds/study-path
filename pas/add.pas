type
        bignum=ansistring;
var
        a,b:bignum;
        c:longint;
procedure nhap;
begin
        readln(a);
        readln(b);
end;
function add(a,b:bignum):bignum;
var     tmp,nho,i:longint;
        x:bignum;
begin
        while length(a)<length(b) do a:='0'+a;
        while length(a)>length(b) do b:='0'+b;
        if a<b then exit(add(b,a));
        nho:=0;x:='';
        for i:=length(a) downto 1 do
        begin
                tmp:=(ord(a[i])+ord(b[i])-2*48+nho);
                x:=chr((tmp mod 10)+48)+x;
                if tmp>=10 then
                begin
                        nho:=1;
                end
                else nho:=0;
        end;
        if nho=1 then x:='1'+x;
        exit(x);
end;
function tru(a,b:bignum):bignum;
var     nho,tmp,i:longint;
        c:bignum;
begin
        while length(a)<length(b) do a:='0'+a;
        while length(a)>length(b) do b:='0'+b;
        if a<b then exit('-'+tru(b,a));
        nho:=0;c:='';
        for i:=length(a) downto 1 do
        begin
                tmp:=ord(a[i])-ord(b[i])-nho;
                if tmp<0 then
                begin
                        tmp:=tmp+10;
                        nho:=1;
                end
                else nho:=0;
                c:=chr(tmp+48)+c;
        end;
        while (length(c)>1) and (c[1]='0') do delete(c,1,1);
        exit(c);
end;
function nhan(a,b:bignum):bignum;
var     c,tmp:bignum;
        i,j,m:longint;
begin
        c:='';m:=-1;
        for i:=length(a) downto 1 do
        begin
                inc(m);
                tmp:='';
                for j:=1 to (ord(a[i])-48) do
                        tmp:=add(tmp,b);
                for j:=1 to m do
                tmp:=tmp+'0';
                c:=add(c,tmp);
        end;
        exit(c);
end;
begin
        assign(input,'add.inp');
        assign(output,'add.out');
        reset(input);
        rewrite(output);
        nhap;
        writeln(add(a,b));
        writeln(tru(a,b));
        writeln(nhan(a,b));
        close(input);
        close(output);
end.
