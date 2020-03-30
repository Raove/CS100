#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class CountVisitor{
    private:
        int ops=0;
        int rands=0;
        int mults=0;
        int divs=0;
        int adds=0;
        int subs=0;
        int pows=0;
        
        int ceils=0;
        int floors=0;
        int abs=0;
        int truncs=0;
        int parens=0;
        int dummy = 0;

    public:
        CountVisitor(){};

        void visit_op()
        {
         ops++;
         return;
        }
        int op_count()
        {
            return ops;
        }
        void visit_rand()
        {
        rands++;
        return;
        }
        int rand_count()
        {
        return rands;
        }
        void visit_mult()
        {
        mults++;
        }
        int mult_count()
        {
        return mults;
        }
        void visit_div()
        {
        divs++;
        }
        int div_count()
        {
        return divs;
        }
        void visit_add()
        {
        adds++;
        return;
        }
        int add_count()
        {
            return adds;
        }
        void visit_sub()
        {
            subs++;
            return;
        }
        int sub_count()
        {
            return subs;
        }
        void visit_pow()
        {
            pows++;
            return;
        }
        int pow_count()
        {
            return pows;
        }

        void visit_ceil()
        {
            ceils++;
            return;
        }
        int ceil_count()
        {
            return ceils;
        }
        void visit_floor()
        {
            floors++;
            return;
        }
        int floor_count()
        {
            return floors;
        }
        void visit_abs()
        {
            abs++;
            return;
        }
        int abs_count()
        {
            return abs;
        }
        void visit_trunc()
        {
            truncs++;
            return;
        }
        int trunc_count()
        {
            return truncs;
        }
        void visit_paren()
        {
            parens++;
            return;
        }
        int paren_count()
        {
            return parens;
        }
    void visit_dummy()
    {
        dummy++;
        return;
    }
    int dummy_count()
    {
        return dummy;
    }
};

#endif //__COUNT_VISITOR_HPP__
