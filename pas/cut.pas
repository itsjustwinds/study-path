uses math;
Type
          BigNum = ansistring;

var
        a,b,c,d:int64;
        i,t:longint;
        t1,t2,t3:bignum;
{function add(a,b : bigNum): bigNum;
var sum, carry, i, x, y : integer;
c : bigNum;
begin
        carry:=0;c:='';
        while length(a)<length(b) do a:='0'+a;
        while length(b)<length(a) do b:='0'+b;
        for i:=length(a) downto 1 do
        begin
                x:= ord(a[i])-ord('0');
                y:= ord(b[i])-ord('0');
                sum:=x + y + carry;
                carry:=sum div 10;
                c:=chr(sum mod 10 +48)+c;
        end;
        if carry>0 then c:='1'+c;
        add:=c;
end;
function nhan(a,b:bigNum):bigNum;
var     sum,tmp :bigNum;
        m,i,j :integer;
begin

        m:=-1;sum:='';
        for i:=length(a) downto 1 do
        begin
                inc(m);
                tmp:='';
                for j:=1 to ord(a[i])-48 do tmp:=add(tmp,b);
                for j:=1 to m do tmp:=tmp+'0';
                sum:=add(tmp,sum);
        end;
        nhan:=sum;
end;    }
function cong(a,b : bigNum): bigNum;
var sum, carry, i, x, y : integer;
        c : bigNum;
begin
        carry:=0;c:='';
        while length(a)<length(b) do a:='0'+a;
        while length(b)<length(a) do b:='0'+b;
        for i:=length(a) downto 1 do
        begin
                x:= ord(a[i])-ord('0'); {ord('0')=48}
                y:= ord(b[i])-ord('0');
                sum:=x + y + carry;
                carry:=sum div 10;
                c:=chr(sum mod 10 +48)+c;
        end;
        if carry>0 then c:='1'+c;
        cong:=c;
end;
function nhan1(a:bigNum;b:longint):bigNum;
var     i :integer;
        carry,s :longint;
        c,tmp :bigNum;
begin
        c:='';
        carry:=0;
        for i:=length(a) downto 1 do
        begin
                s:=(ord(a[i])-48) * b + carry;
                carry:= s div 10;
                c:=chr(s mod 10 + 48)+c;
        end;
        if carry>0 then str(carry,tmp) else tmp:='';
        nhan1:=tmp+c;
end;
function nhan2(a,b:bigNum):bigNum;
var sum,tmp :bigNum;
        m,i,j :integer;
begin
        m:=-1;sum:='';
        for i:=length(a) downto 1 do
        begin
                m:=m+1;
                tmp:=nhan1(b,ord(a[i])-48);
                for j:=1 to m do tmp:=tmp+'0';
                        sum:=cong(tmp,sum);
        end;
        nhan2:=sum;
end;
procedure nhap;
var     s1,s2,s3:bignum;
        d,maxl:longint;
        tmp:int64;
begin
        readln(t);
        while t>0 do
        begin
        dec(t);
        read(a,b,c,d);
        while d>0 do
        begin
                str(a,s1);
                str(b,s2);
                str(c,s3);
                t1:=nhan2(s1,s2);//a*b
                t2:=nhan2(s2,s3);//b*c
                t3:=nhan2(s1,s3);//c*a
                maxl:=max(length(t1),max(length(t2),length(t3)));
                while length(t1)<maxl do t1:='0'+t1;
                while length(t2)<maxl do t2:='0'+t2;
                while length(t3)<maxl do t3:='0'+t3;
                if (t1<=t2) and (t1<=t3) then dec(c)
                else
                if (t2<=t1) and (t2<=t3) then dec(a)
                else
                if (t3<=t1) and (t3<=t2) then dec(b);
                dec(d);
        end;
        str(a,s1);
        str(b,s2);
        str(c,s3);
        writeln(nhan2(nhan2(s1,s2),s3));
        end;
end;
begin
        assign(input,'cut.inp');
        assign(output,'cut.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
