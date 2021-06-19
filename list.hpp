template <class _Tp, class _VoidPtr>
class _LIBCPP_TEMPLATE_VIS __list_iterator
{
	template<class, class> friend class list;
	template<class, class> friend class __list_imp;
	template<class, class> friend class __list_const_iterator;
public:
	typedef bidirectional_iterator_tag       iterator_category;
	typedef _Tp                              value_type;
	typedef value_type&                      reference;
	typedef typename __rebind_pointer<_VoidPtr, value_type>::type pointer;
	typedef typename pointer_traits<pointer>::difference_type difference_type;


	__list_iterator(const __list_iterator& __p)

	~__list_iterator()

	__list_iterator& operator=(const __list_iterator& __p)

	reference operator*() const

	pointer operator->() const

	__list_iterator& operator++()

	__list_iterator operator++(int)

	__list_iterator& operator--()

	__list_iterator operator--(int)

	bool operator==(const __list_iterator& __x, const __list_iterator& __y)

	 bool operator!=(const __list_iterator& __x, const __list_iterator& __y)
};


------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------
template <class _Tp, class _Alloc /*= allocator<_Tp>*/>
class list
	: private __list_imp<_Tp, _Alloc>
{
	typedef __list_imp<_Tp, _Alloc> base;
	typedef typename base::__node              __node;
	typedef typename base::__node_allocator    __node_allocator;
	typedef typename base::__node_pointer      __node_pointer;
	typedef typename base::__node_alloc_traits __node_alloc_traits;
	typedef typename base::__node_base         __node_base;
	typedef typename base::__node_base_pointer __node_base_pointer;
	typedef typename base::__link_pointer __link_pointer;

public:
	typedef _Tp                                      value_type;
	typedef _Alloc                                   allocator_type;
	static_assert((is_same<value_type, typename allocator_type::value_type>::value),
				  "Invalid allocator::value_type");
	typedef value_type&                              reference;
	typedef const value_type&                        const_reference;
	typedef typename base::pointer                   pointer;
	typedef typename base::const_pointer             const_pointer;
	typedef typename base::size_type                 size_type;
	typedef typename base::difference_type           difference_type;
	typedef typename base::iterator                  iterator;
	typedef typename base::const_iterator            const_iterator;
	typedef _VSTD::reverse_iterator<iterator>         reverse_iterator;
	typedef _VSTD::reverse_iterator<const_iterator>   const_reverse_iterator;

	_LIBCPP_INLINE_VISIBILITY
	list()

	list(size_type __n);

	list(size_type __n, const value_type& __x);

	list(const list& __c);

	list& operator=(const list& __c);

	list& operator=(list&& __c)

	void assign(initializer_list<value_type> __il)
		{assign(__il.begin(), __il.end());}

	void assign(size_type __n, const value_type& __x);

	size_type size() const _NOEXCEPT     {return base::__sz();}

	bool empty() const _NOEXCEPT         {return base::empty();}

	size_type max_size() const _NOEXCEPT
		{
			return std::min<size_type>(
				base::__node_alloc_max_size(),
				numeric_limits<difference_type >::max());
		}

	iterator begin() _NOEXCEPT        {return base::begin();}

	const_iterator begin()  const _NOEXCEPT {return base::begin();}

	iterator end() _NOEXCEPT          {return base::end();}

	const_iterator end()    const _NOEXCEPT {return base::end();}

	const_iterator cbegin() const _NOEXCEPT {return base::begin();}

	const_iterator cend()   const _NOEXCEPT {return base::end();}

	reverse_iterator rbegin() _NOEXCEPT
		{return       reverse_iterator(end());}

	const_reverse_iterator rbegin()  const _NOEXCEPT
		{return const_reverse_iterator(end());}

	reverse_iterator rend() _NOEXCEPT
		{return       reverse_iterator(begin());}

	const_reverse_iterator rend()    const _NOEXCEPT
		{return const_reverse_iterator(begin());}

	const_reverse_iterator crbegin() const _NOEXCEPT
		{return const_reverse_iterator(end());}

	const_reverse_iterator crend()   const _NOEXCEPT
		{return const_reverse_iterator(begin());}


	reference front()
	{
		_LIBCPP_ASSERT(!empty(), "list::front called on empty list");
		return base::__end_.__next_->__as_node()->__value_;
	}

	const_reference front() const
	{
		_LIBCPP_ASSERT(!empty(), "list::front called on empty list");
		return base::__end_.__next_->__as_node()->__value_;
	}

	reference back()
	{
		_LIBCPP_ASSERT(!empty(), "list::back called on empty list");
		return base::__end_.__prev_->__as_node()->__value_;
	}

	const_reference back() const
	{
		_LIBCPP_ASSERT(!empty(), "list::back called on empty list");
		return base::__end_.__prev_->__as_node()->__value_;
	}

	void push_front(const value_type& __x);
	void push_back(const value_type& __x);

	iterator insert(const_iterator __p, const value_type& __x);
	iterator insert(const_iterator __p, size_type __n, const value_type& __x);

	void swap(list& __c)
		{base::swap(__c);}

	void clear() _NOEXCEPT {base::clear();}

	void pop_back();
	void pop_front();

	iterator erase(const_iterator __p);
	iterator erase(const_iterator __f, const_iterator __l);

	void resize(size_type __n);
	void resize(size_type __n, const value_type& __x);

	void splice(const_iterator __p, list& __c);
	void splice(const_iterator __p, list& __c, const_iterator __i);
	void splice(const_iterator __p, list& __c, const_iterator __f, const_iterator __l);

	void remove(const value_type& __x);

	template <class _Pred> void remove_if(_Pred __pred);

	void unique();

	void unique(_BinaryPred __binary_pred);

	void merge(list& __c);

	template <class _Comp>
		void merge(list& __c, _Comp __comp);

	void sort();
	template <class _Comp>
		_LIBCPP_INLINE_VISIBILITY
		void sort(_Comp __comp);

	void reverse() _NOEXCEPT;
