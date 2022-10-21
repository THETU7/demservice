// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dem_service.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_dem_5fservice_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_dem_5fservice_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_dem_5fservice_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_dem_5fservice_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_dem_5fservice_2eproto;
namespace dem_service {
class GetHeightReply;
struct GetHeightReplyDefaultTypeInternal;
extern GetHeightReplyDefaultTypeInternal _GetHeightReply_default_instance_;
class GetHeightRequest;
struct GetHeightRequestDefaultTypeInternal;
extern GetHeightRequestDefaultTypeInternal _GetHeightRequest_default_instance_;
}  // namespace dem_service
PROTOBUF_NAMESPACE_OPEN
template<> ::dem_service::GetHeightReply* Arena::CreateMaybeMessage<::dem_service::GetHeightReply>(Arena*);
template<> ::dem_service::GetHeightRequest* Arena::CreateMaybeMessage<::dem_service::GetHeightRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace dem_service {

// ===================================================================

class GetHeightRequest final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:dem_service.GetHeightRequest) */ {
 public:
  inline GetHeightRequest() : GetHeightRequest(nullptr) {}
  ~GetHeightRequest() override;
  explicit PROTOBUF_CONSTEXPR GetHeightRequest(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GetHeightRequest(const GetHeightRequest& from);
  GetHeightRequest(GetHeightRequest&& from) noexcept
    : GetHeightRequest() {
    *this = ::std::move(from);
  }

  inline GetHeightRequest& operator=(const GetHeightRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetHeightRequest& operator=(GetHeightRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const GetHeightRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const GetHeightRequest* internal_default_instance() {
    return reinterpret_cast<const GetHeightRequest*>(
               &_GetHeightRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GetHeightRequest& a, GetHeightRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(GetHeightRequest* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GetHeightRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GetHeightRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GetHeightRequest>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const GetHeightRequest& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const GetHeightRequest& from) {
    GetHeightRequest::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GetHeightRequest* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "dem_service.GetHeightRequest";
  }
  protected:
  explicit GetHeightRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kWktsFieldNumber = 1,
    kIsTransFieldNumber = 2,
  };
  // repeated string wkts = 1;
  int wkts_size() const;
  private:
  int _internal_wkts_size() const;
  public:
  void clear_wkts();
  const std::string& wkts(int index) const;
  std::string* mutable_wkts(int index);
  void set_wkts(int index, const std::string& value);
  void set_wkts(int index, std::string&& value);
  void set_wkts(int index, const char* value);
  void set_wkts(int index, const char* value, size_t size);
  std::string* add_wkts();
  void add_wkts(const std::string& value);
  void add_wkts(std::string&& value);
  void add_wkts(const char* value);
  void add_wkts(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& wkts() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_wkts();
  private:
  const std::string& _internal_wkts(int index) const;
  std::string* _internal_add_wkts();
  public:

  // bool is_trans = 2;
  void clear_is_trans();
  bool is_trans() const;
  void set_is_trans(bool value);
  private:
  bool _internal_is_trans() const;
  void _internal_set_is_trans(bool value);
  public:

  // @@protoc_insertion_point(class_scope:dem_service.GetHeightRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> wkts_;
    bool is_trans_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_dem_5fservice_2eproto;
};
// -------------------------------------------------------------------

class GetHeightReply final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:dem_service.GetHeightReply) */ {
 public:
  inline GetHeightReply() : GetHeightReply(nullptr) {}
  ~GetHeightReply() override;
  explicit PROTOBUF_CONSTEXPR GetHeightReply(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GetHeightReply(const GetHeightReply& from);
  GetHeightReply(GetHeightReply&& from) noexcept
    : GetHeightReply() {
    *this = ::std::move(from);
  }

  inline GetHeightReply& operator=(const GetHeightReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetHeightReply& operator=(GetHeightReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const GetHeightReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const GetHeightReply* internal_default_instance() {
    return reinterpret_cast<const GetHeightReply*>(
               &_GetHeightReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(GetHeightReply& a, GetHeightReply& b) {
    a.Swap(&b);
  }
  inline void Swap(GetHeightReply* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GetHeightReply* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GetHeightReply* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GetHeightReply>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const GetHeightReply& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const GetHeightReply& from) {
    GetHeightReply::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GetHeightReply* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "dem_service.GetHeightReply";
  }
  protected:
  explicit GetHeightReply(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kWktsFieldNumber = 1,
  };
  // repeated string wkts = 1;
  int wkts_size() const;
  private:
  int _internal_wkts_size() const;
  public:
  void clear_wkts();
  const std::string& wkts(int index) const;
  std::string* mutable_wkts(int index);
  void set_wkts(int index, const std::string& value);
  void set_wkts(int index, std::string&& value);
  void set_wkts(int index, const char* value);
  void set_wkts(int index, const char* value, size_t size);
  std::string* add_wkts();
  void add_wkts(const std::string& value);
  void add_wkts(std::string&& value);
  void add_wkts(const char* value);
  void add_wkts(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& wkts() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_wkts();
  private:
  const std::string& _internal_wkts(int index) const;
  std::string* _internal_add_wkts();
  public:

  // @@protoc_insertion_point(class_scope:dem_service.GetHeightReply)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> wkts_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_dem_5fservice_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetHeightRequest

// repeated string wkts = 1;
inline int GetHeightRequest::_internal_wkts_size() const {
  return _impl_.wkts_.size();
}
inline int GetHeightRequest::wkts_size() const {
  return _internal_wkts_size();
}
inline void GetHeightRequest::clear_wkts() {
  _impl_.wkts_.Clear();
}
inline std::string* GetHeightRequest::add_wkts() {
  std::string* _s = _internal_add_wkts();
  // @@protoc_insertion_point(field_add_mutable:dem_service.GetHeightRequest.wkts)
  return _s;
}
inline const std::string& GetHeightRequest::_internal_wkts(int index) const {
  return _impl_.wkts_.Get(index);
}
inline const std::string& GetHeightRequest::wkts(int index) const {
  // @@protoc_insertion_point(field_get:dem_service.GetHeightRequest.wkts)
  return _internal_wkts(index);
}
inline std::string* GetHeightRequest::mutable_wkts(int index) {
  // @@protoc_insertion_point(field_mutable:dem_service.GetHeightRequest.wkts)
  return _impl_.wkts_.Mutable(index);
}
inline void GetHeightRequest::set_wkts(int index, const std::string& value) {
  _impl_.wkts_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:dem_service.GetHeightRequest.wkts)
}
inline void GetHeightRequest::set_wkts(int index, std::string&& value) {
  _impl_.wkts_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:dem_service.GetHeightRequest.wkts)
}
inline void GetHeightRequest::set_wkts(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.wkts_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:dem_service.GetHeightRequest.wkts)
}
inline void GetHeightRequest::set_wkts(int index, const char* value, size_t size) {
  _impl_.wkts_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:dem_service.GetHeightRequest.wkts)
}
inline std::string* GetHeightRequest::_internal_add_wkts() {
  return _impl_.wkts_.Add();
}
inline void GetHeightRequest::add_wkts(const std::string& value) {
  _impl_.wkts_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:dem_service.GetHeightRequest.wkts)
}
inline void GetHeightRequest::add_wkts(std::string&& value) {
  _impl_.wkts_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:dem_service.GetHeightRequest.wkts)
}
inline void GetHeightRequest::add_wkts(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.wkts_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:dem_service.GetHeightRequest.wkts)
}
inline void GetHeightRequest::add_wkts(const char* value, size_t size) {
  _impl_.wkts_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:dem_service.GetHeightRequest.wkts)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
GetHeightRequest::wkts() const {
  // @@protoc_insertion_point(field_list:dem_service.GetHeightRequest.wkts)
  return _impl_.wkts_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
GetHeightRequest::mutable_wkts() {
  // @@protoc_insertion_point(field_mutable_list:dem_service.GetHeightRequest.wkts)
  return &_impl_.wkts_;
}

// bool is_trans = 2;
inline void GetHeightRequest::clear_is_trans() {
  _impl_.is_trans_ = false;
}
inline bool GetHeightRequest::_internal_is_trans() const {
  return _impl_.is_trans_;
}
inline bool GetHeightRequest::is_trans() const {
  // @@protoc_insertion_point(field_get:dem_service.GetHeightRequest.is_trans)
  return _internal_is_trans();
}
inline void GetHeightRequest::_internal_set_is_trans(bool value) {
  
  _impl_.is_trans_ = value;
}
inline void GetHeightRequest::set_is_trans(bool value) {
  _internal_set_is_trans(value);
  // @@protoc_insertion_point(field_set:dem_service.GetHeightRequest.is_trans)
}

// -------------------------------------------------------------------

// GetHeightReply

// repeated string wkts = 1;
inline int GetHeightReply::_internal_wkts_size() const {
  return _impl_.wkts_.size();
}
inline int GetHeightReply::wkts_size() const {
  return _internal_wkts_size();
}
inline void GetHeightReply::clear_wkts() {
  _impl_.wkts_.Clear();
}
inline std::string* GetHeightReply::add_wkts() {
  std::string* _s = _internal_add_wkts();
  // @@protoc_insertion_point(field_add_mutable:dem_service.GetHeightReply.wkts)
  return _s;
}
inline const std::string& GetHeightReply::_internal_wkts(int index) const {
  return _impl_.wkts_.Get(index);
}
inline const std::string& GetHeightReply::wkts(int index) const {
  // @@protoc_insertion_point(field_get:dem_service.GetHeightReply.wkts)
  return _internal_wkts(index);
}
inline std::string* GetHeightReply::mutable_wkts(int index) {
  // @@protoc_insertion_point(field_mutable:dem_service.GetHeightReply.wkts)
  return _impl_.wkts_.Mutable(index);
}
inline void GetHeightReply::set_wkts(int index, const std::string& value) {
  _impl_.wkts_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set:dem_service.GetHeightReply.wkts)
}
inline void GetHeightReply::set_wkts(int index, std::string&& value) {
  _impl_.wkts_.Mutable(index)->assign(std::move(value));
  // @@protoc_insertion_point(field_set:dem_service.GetHeightReply.wkts)
}
inline void GetHeightReply::set_wkts(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.wkts_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:dem_service.GetHeightReply.wkts)
}
inline void GetHeightReply::set_wkts(int index, const char* value, size_t size) {
  _impl_.wkts_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:dem_service.GetHeightReply.wkts)
}
inline std::string* GetHeightReply::_internal_add_wkts() {
  return _impl_.wkts_.Add();
}
inline void GetHeightReply::add_wkts(const std::string& value) {
  _impl_.wkts_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:dem_service.GetHeightReply.wkts)
}
inline void GetHeightReply::add_wkts(std::string&& value) {
  _impl_.wkts_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:dem_service.GetHeightReply.wkts)
}
inline void GetHeightReply::add_wkts(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _impl_.wkts_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:dem_service.GetHeightReply.wkts)
}
inline void GetHeightReply::add_wkts(const char* value, size_t size) {
  _impl_.wkts_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:dem_service.GetHeightReply.wkts)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
GetHeightReply::wkts() const {
  // @@protoc_insertion_point(field_list:dem_service.GetHeightReply.wkts)
  return _impl_.wkts_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
GetHeightReply::mutable_wkts() {
  // @@protoc_insertion_point(field_mutable_list:dem_service.GetHeightReply.wkts)
  return &_impl_.wkts_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace dem_service

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_dem_5fservice_2eproto
